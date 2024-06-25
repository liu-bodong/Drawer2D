#pragma once
#include "Shape.h"
class Rect :
    public Shape
{
public:
    Rect() = default;
    ~Rect() override = default;
    void Paint(QPainter& painter) override
    {
        painter.drawRect(m_start.x(), m_start.y(), m_end.x() - m_start.x(), m_end.y() - m_start.y());
    }
};

