#pragma once
#include "Shape.h"
class Line :
    public Shape
{
public:
    Line() = default;
    ~Line() override = default;
    void Paint(QPainter& painter) override
    {
        painter.drawLine(m_start, m_end);
    }
};

