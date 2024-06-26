#pragma once
#include "Shape.h"


class IEllipse :
    public Shape
{
public:
    IEllipse() = default;
    ~IEllipse() override = default;
    void Paint(QPainter& painter) override;

    QPoint m_center;
    int m_radiusX;
    int m_radiusY;
};



