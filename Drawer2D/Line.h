#pragma once
#include "Shape.h"
class Line :
    public Shape
{
public:
    Line() = default;
    ~Line() override = default;
    void Paint(QPainter& painter) override;
};

