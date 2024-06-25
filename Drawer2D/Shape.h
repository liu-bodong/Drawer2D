#pragma once
#include <QPainter>

class Shape
{
public:
    enum ShapeType
    {
        eLine,
        eRect,
        eCircle,
        eEllipse
    };
    Shape() = default;
    virtual ~Shape() = default;

    void SetStartPoint(const QPoint& p) { m_start = p; }
    void SetEndPoint(const QPoint& p) { m_end = p; }
    QPoint GetStartPoint() const { return m_start; }
    QPoint GetEndPoint() const { return m_end; }

    void virtual Paint(QPainter& painter) = 0;

protected:
    QPoint m_start;
    QPoint m_end;
};
