#include "Command.h"
#include "MainWindow.h"
#include <qpalette.h>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    InitUI();
    MakeConnections();

    (ui.canvasWidget)->m_pInvoker = m_pInvoker;
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
    m_pInvoker->DoCommand(new ClearCommand(ui.canvasWidget));
}

void MainWindow::MakeConnections() const
{
    connect(ui.actionClear, SIGNAL(triggered()), this, SLOT(on_Clear_Clicked()));

    connect(ui.actionDrawLine, SIGNAL(triggered()), this, SLOT(actionDrawLineTriggered()));
    connect(ui.actionDrawRectangle, SIGNAL(triggered()), this, SLOT(actionDrawRecTriggered()));
    connect(ui.actionDrawCircle, SIGNAL(triggered()), this, SLOT(actionDrawCircleTriggered()));
    connect(ui.actionDrawEllipse, SIGNAL(triggered()), this, SLOT(actionDrawEllipseTriggered()));

    connect(this, SIGNAL(changeShape(Shape::ShapeType)), ui.canvasWidget, SLOT(setCurShape(Shape::ShapeType)));

    connect(ui.actionUndo, SIGNAL(triggered()), this, SLOT(on_Undo_Clicked()));
    connect(ui.actionRedo, SIGNAL(triggered()), this, SLOT(on_Redo_Clicked()));

    connect(ui.sizeSpinBox, SIGNAL(valueChanged(int)), ui.canvasWidget, SLOT(setPenSize(int)));
    connect(ui.colorComboBox, SIGNAL(currentTextChanged(const QString&)), ui.canvasWidget, SLOT(setPenColor(const QString&)));
}

void MainWindow::InitUI()
{
    auto pShapeGroup = new QActionGroup(this);
    pShapeGroup->addAction(ui.actionDrawLine);
    pShapeGroup->addAction(ui.actionDrawRectangle);
    pShapeGroup->addAction(ui.actionDrawCircle);
    pShapeGroup->addAction(ui.actionDrawEllipse);
    pShapeGroup->addAction(ui.actionDrawText);
    QPalette pal = QPalette();

    // set black background
    // Qt::black / "#000000" / "black"
    pal.setColor(QPalette::Window, Qt::white);
    ui.canvasWidget->setAutoFillBackground(true);
    ui.canvasWidget->setPalette(pal);

    pal.setColor(QPalette::Window, "#e7e7e7");
    this->setAutoFillBackground(true);
    this->setPalette(pal);
}