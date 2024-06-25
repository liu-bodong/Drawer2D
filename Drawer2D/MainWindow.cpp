#include "Command.h"
#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    InitUI();
    MakeConnections();

    (ui.mainWidget)->m_pInvoker = m_pInvoker;
}

void MainWindow::actionDrawLineTriggered()
{
    emit changeShape(Shape::eLine);
}

void MainWindow::actionDrawRecTriggered()
{
    emit changeShape(Shape::eRect);
}

void MainWindow::actionDrawCircleTriggered()
{
    emit changeShape(Shape::eCircle);
}

void MainWindow::actionDrawEllipseTriggered()
{
    emit changeShape(Shape::eEllipse);
}

void MainWindow::on_Undo_Clicked()
{
    m_pInvoker->UndoCommand();
}

void MainWindow::on_Redo_Clicked()
{
    m_pInvoker->RedoCommand();
}

void MainWindow::on_Clear_Clicked()
{
    ui.mainWidget->Clear();
}

void MainWindow::MakeConnections() const
{
    connect(ui.actionClear, SIGNAL(triggered), this, SLOT(on_Clear_Clicked()));

    connect(ui.actionDrawLine, SIGNAL(triggered()), this, SLOT(actionDrawLineTriggered()));
    connect(ui.actionDrawRectangle, SIGNAL(triggered()), this, SLOT(actionDrawRecTriggered()));
    connect(ui.actionDrawCircle, SIGNAL(triggered()), this, SLOT(actionDrawCircleTriggered()));
    connect(ui.actionDrawEllipse, SIGNAL(triggered()), this, SLOT(actionDrawEllipseTriggered()));

    connect(this, SIGNAL(changeShape(Shape::ShapeType)), ui.mainWidget, SLOT(setCurShape(Shape::ShapeType)));

    connect(ui.actionUndo, SIGNAL(triggered()), this, SLOT(on_Undo_Clicked()));
    connect(ui.actionRedo, SIGNAL(triggered()), this, SLOT(on_Redo_Clicked()));

    connect(ui.sizeSpinBox, SIGNAL(valuedChanged(int)), ui.mainWidget, SLOT(setPenSize(int)));
    connect(ui.colorComboBox, SIGNAL(currentTextChanged(const QString&)), ui.mainWidget, SLOT(setPenColor(const QString&)));
}

void MainWindow::InitUI()
{
    auto pShapeGroup = new QActionGroup(this);
    pShapeGroup->addAction(ui.actionDrawLine);
    pShapeGroup->addAction(ui.actionDrawRectangle);
    pShapeGroup->addAction(ui.actionDrawCircle);
    pShapeGroup->addAction(ui.actionDrawEllipse);
    pShapeGroup->addAction(ui.actionDrawText);
}