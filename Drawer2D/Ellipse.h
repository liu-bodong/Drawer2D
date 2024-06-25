#pragma once
#include "Shape.h"


class IEllipse :
    public Shape
{
public:
    IEllipse() = default;
    ~IEllipse() override = default;
    void Paint(QPainter& painter) override
    {
        painter.drawEllipse(m_start.x(), m_start.y(), m_end.x() - m_start.x(), m_end.y() - m_start.y());
    }
};



