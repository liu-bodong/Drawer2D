#pragma once
#include "Invoker.h"
#include <qwidget.h>
#include "Shape.h"
#include <qpen.h>
#include <qobjectdefs.h>
#include <qevent.h>
#include "Item.h"
#include "Memento.h"
#include <memory>
#include <qlist.h>

class Invoker;
class Command;


class CanvasWidget : public QWidget
{
    Q_OBJECT

public:
    enum Mode { eDraw, eSelect };
    CanvasWidget(QWidget* parent = nullptr);
    ~CanvasWidget() = default;

    void AddShape(std::shared_ptr<Shape>, QPen);    // Add a shape to the list of shapes
    void SetCurVer(QList<std::shared_ptr<Item>>);   // Set the current version of the shapes
    Memento* CreateMemento();                       // Create a memento
    QList<std::shared_ptr<Item>> GetShapes() const; // Get the list of shapes
    void Clear();                                   // Clear the list of shapes
    Invoker* m_pInvoker;                            // The invoker that is used to undo and redo commands


public slots:
    void setCurShape(Shape::ShapeType);
    void setPenSize(int);
    void setPenColor(const QString&);
    void setMode(CanvasWidget::Mode);

protected:
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);
    void mouseDoubleClickEvent(QMouseEvent*);

private:
    std::shared_ptr<Shape> m_pShape = nullptr;   // The shape that is being currently edited
    Shape::ShapeType m_shapeType = Shape::eLine; // The type of the shape that is being drawn
    bool m_perm = false;                         // Whether there is a shape being drawn at the moment
    QList<std::shared_ptr<Item>> m_shapes;       // The list of shapes that have been drawn
    QPen m_pen;                                  // The pen that is used to draw the shapes
    Mode m_mode = eDraw;                         // The mode of the canvas, default to eDraw
    void Draw(QMouseEvent*);                     // Draw the shapes
    void Select(QMouseEvent*);                   // Select a shape
};
