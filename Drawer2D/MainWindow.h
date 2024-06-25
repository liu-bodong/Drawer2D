#pragma once

#include "Shape.h"
#include "Invoker.h"
#include "ui_DrawerMainWindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow() = default;

signals:
    void changeShape(Shape::ShapeType);

public slots:
    void actionDrawLineTriggered();
    void actionDrawRecTriggered();
    void actionDrawCircleTriggered();
    void actionDrawEllipseTriggered();
    void on_Undo_Clicked();
    void on_Redo_Clicked();
    void on_Clear_Clicked();

private:
    Ui::DrawerMainWindowClass ui;
    Invoker* m_pInvoker = new Invoker();
    // Command* m_command;

    void MakeConnections() const;
    void InitUI();
};
