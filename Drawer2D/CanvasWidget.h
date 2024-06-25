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
    CanvasWidget(QWidget* parent = nullptr);
    ~CanvasWidget() = default;

    void AddShape(std::shared_ptr<Shape>, QPen);
    void SetCurVer(QList<std::shared_ptr<Item>>);
    Memento* CreateMemento();
    QList<std::shared_ptr<Item>> GetShapes() const;

    void Clear();


public slots:
    void setCurShape(Shape::ShapeType);
    void setPenSize(int);
    void setPenColor(const QString&);


protected:
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);

private:
    std::shared_ptr<Shape> m_pShape = nullptr;
    Shape::ShapeType m_shapeType = Shape::eLine;
    bool m_perm = false;
    QList<std::shared_ptr<Item>> m_shapes;
    QPen m_pen;

    std::shared_ptr<Invoker> m_invoker = std::make_shared<Invoker>();
    Command* m_command;
};
