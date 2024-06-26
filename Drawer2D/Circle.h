#pragma once
#include "Shape.h"
class Circle :
    public Shape
{
public:
    Circle() = default;
    ~Circle() override = default;
    void Paint(QPainter& painter) override;

    QPoint m_center;
    int m_radius = 0;
};