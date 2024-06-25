#pragma once
#include "Shape.h"
class Circle :
    public Shape
{
public:
    Circle() = default;
    ~Circle() override = default;
    void Paint(QPainter& painter) override
    {
        double rad = sqrt(pow(m_end.x() - m_start.x(), 2) + pow(m_end.y() - m_start.y(), 2));
        auto roundedRad = static_cast<int>(rad);
        painter.drawEllipse(m_start, roundedRad, roundedRad);
    }
};