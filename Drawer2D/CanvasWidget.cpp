#include "CanvasWidget.h"
#include "Line.h"
#include "Rect.h"
#include "Circle.h"
#include "Ellipse.h"
#include <qpainterpath.h>
#include <qdebug.h>

#include "Command.h"


CanvasWidget::CanvasWidget(QWidget* parent)
    : QWidget(parent)
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QPainterPath path;
}

void CanvasWidget::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    for (std::shared_ptr<Item> item : m_shapes) {
        painter.setPen(item->getPen());
        (item->getShape())->Paint(painter);
    }
}

void CanvasWidget::mousePressEvent(QMouseEvent* event)
{
    if (m_mode == eDraw) {
        Draw(event);
    }
    else if (m_mode == eSelect) {
        Select(event);
    }
}

void CanvasWidget::mouseMoveEvent(QMouseEvent* event) {

    if (m_pShape && !m_perm) {
        m_pShape->SetEndPoint(event->pos());
        update();
    }
}

void CanvasWidget::Draw(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        m_perm = true;

        if (m_pShape != nullptr) {
            /*if (m_pInvoker->UndoEmpty())
            { m_pInvoker->DoCommand(new DrawCommand(this)); }*/
            m_perm = false;
            AddShape(m_pShape, m_pen);
            // pass in the points
        }
    }
}

void CanvasWidget::Select(QMouseEvent* event)
{
    // implement select

}

void CanvasWidget::mouseDoubleClickEvent(QMouseEvent* event)
{
    // TODO: implement double click event
    return;
}

void CanvasWidget::mouseReleaseEvent(QMouseEvent* event)
{
    m_pInvoker->DoCommand(new DrawCommand(this));
    m_perm = true;
}

void CanvasWidget::AddShape(std::shared_ptr<Shape> shape, QPen pen)
{
    auto item = std::make_shared<Item>(shape, pen);
    m_shapes.append(item);
}

void CanvasWidget::Clear()
{
    m_shapes.clear();
}

void CanvasWidget::setPenSize(int i)
{
    m_pen.setWidth(i);
}

void CanvasWidget::setPenColor(const QString& text)
{
    QColor color(text);
    m_pen.setColor(color);
}

QList<std::shared_ptr<Item>> CanvasWidget::GetShapes() const
{
    return m_shapes;
}

void CanvasWidget::SetCurVer(QList<std::shared_ptr<Item>> shapes)
{
    m_shapes = shapes;
}

Memento* CanvasWidget::CreateMemento()
{
    return new Memento(this);
}

void CanvasWidget::setMode(CanvasWidget::Mode mode)
{
    m_mode = mode;
}