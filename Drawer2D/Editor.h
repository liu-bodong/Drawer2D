#pragma once
#include <qgraphicsview.h>
#include <qwidget.h>
#include <qgraphicsitem.h>

class Editor : public QGraphicsView
{
    Q_OBJECT

public:
    Editor(QWidget* parent = nullptr);
    ~Editor() = default;

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void paintEvent(QPaintEvent* event) override;

public slots:

private:
    QGraphicsItem* m_Item;

private:
    QPixmap pix;
    QPoint lastPoint;
    QPoint endPoint;
    QPixmap tempPix;
    bool isDrawing;
};