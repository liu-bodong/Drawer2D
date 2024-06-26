#pragma once
#include <qpainter.h>
#include <qpoint.h>

class Shape
{
public:
    Shape() = default;
    virtual ~Shape() = default;
    void virtual Paint(QPainter&) = 0;
};
