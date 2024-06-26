#pragma once
#include "Shape.h"
class Rect :
    public Shape
{
public:
    Rect() = default;
    ~Rect() override = default;
    void Paint(QPainter& painter) override;

    QPoint m_upperLeft;
    QPoint m_lowerRight;
    int m_width = 0;
    int m_height = 0;
};

