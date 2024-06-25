#include "Command.h"
#include "MainWindow.h"
#include <qpalette.h>
#include <qcursor.h>
#include <qpixmap.h>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    InitUI();
    MakeConnections();

    (ui.canvasWidget)->m_pInvoker = m_pInvoker;
}

void MainWindow::MakeConnections() const
{
    // actions
    connect(ui.actionClear, SIGNAL(triggered()), this, SLOT(on_Clear_Clicked()));
    connect(ui.actionUndo, SIGNAL(triggered()), this, SLOT(on_Undo_Clicked()));
    connect(ui.actionRedo, SIGNAL(triggered()), this, SLOT(on_Redo_Clicked()));

    // toggle shapes
    connect(ui.actionDrawLine, SIGNAL(triggered()), this, SLOT(actionDrawLineTriggered()));
    connect(ui.actionDrawRectangle, SIGNAL(triggered()), this, SLOT(actionDrawRecTriggered()));
    connect(ui.actionDrawCircle, SIGNAL(triggered()), this, SLOT(actionDrawCircleTriggered()));
    connect(ui.actionDrawEllipse, SIGNAL(triggered()), this, SLOT(actionDrawEllipseTriggered()));
    connect(this, SIGNAL(changeShape(Shape::ShapeType)), ui.canvasWidget, SLOT(setCurShape(Shape::ShapeType)));

    // toggle mode
    connect(ui.actionDraw, SIGNAL(toggled(bool)), this, SLOT(actionDrawToggled()));
    connect(ui.actionSelect, SIGNAL(toggled(bool)), this, SLOT(actionSelectToggled()));
    connect(this, SIGNAL(changeMode(CanvasWidget::Mode)), ui.canvasWidget, SLOT(setMode(CanvasWidget::Mode)));


    // properties
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

    ui.actionDrawLine->setChecked(true);


    auto pModeGroup = new QActionGroup(this);
    pModeGroup->addAction(ui.actionDraw);
    pModeGroup->addAction(ui.actionSelect);

    ui.actionDraw->setChecked(true);

    // set black background
    // Qt::black / "#000000" / "black"
    auto pal = QPalette();
    pal.setColor(QPalette::Window, Qt::white);
    ui.canvasWidget->setAutoFillBackground(true);
    ui.canvasWidget->setPalette(pal);
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

void MainWindow::actionDrawToggled()
{
    emit changeMode(CanvasWidget::eDraw);
    ui.canvasWidget->setCursor(Qt::CrossCursor);
}

void MainWindow::actionSelectToggled()
{
    emit changeMode(CanvasWidget::eSelect);
    ui.canvasWidget->setCursor(QCursor(QPixmap(":/DrawerMainWindow/Resources/pixil-frame-0.png"), 10, 10));
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