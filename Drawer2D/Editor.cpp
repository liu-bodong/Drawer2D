#include "Editor.h"
#include <qgraphicsview.h>
#include <qpainter.h>
#include <qgraphicsscene.h>
#include <qpoint.h>
#include <qevent.h>
#include <qdebug.h>


Editor::Editor(QWidget* parent)
    : QGraphicsView(parent), isDrawing(false)
{
    auto scene = new QGraphicsScene(this);
    setScene(scene);
}

void Editor::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        lastPoint = event->pos();
        qDebug() << lastPoint.x();
        isDrawing = true;
    }
}

void Editor::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        endPoint = event->pos();
        qDebug() << endPoint.x();
        isDrawing = false;
        //update();
    }
}

void Editor::mouseMoveEvent(QMouseEvent* event)
{
    if (event->buttons() & Qt::LeftButton) {
        endPoint = event->pos();
        qDebug() << endPoint.x();
        viewport()->update();
    }
}

void Editor::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

    auto path = QPainterPath(lastPoint);
    path.lineTo(endPoint);

    painter.setRenderHint(QPainter::Antialiasing, true);

    //painter.drawLine(lastPoint, endPoint);
    painter.drawPath(path);

    //for (std::shared_ptr<Item> item : m_shapes) {
    //    painter.setPen(item->getPen());
    //    (item->getShape())->Paint(painter);
    //}




    //if (isDrawing)
    //{
    //    tempPix = pix;
    //    QPainter pp(&tempPix);
    //    pp.drawLine(lastPoint, endPoint);
    //    painter.drawPixmap(0, 0, tempPix);
    //}
    //else
    //{

    //    QPainter pp(&pix);
    //    pp.drawLine(200, 200, 300, 300);
    //    pp.drawLine(lastPoint, endPoint);
    //    painter.drawPixmap(0, 0, pix);
    //}
}
