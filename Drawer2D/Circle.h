#pragma once
#include "Shape.h"
class Circle :
    public Shape
{
public:
    Circle() = default;
    ~Circle() override = default;
    void Paint(QPainter& painter) override;
};