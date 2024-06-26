#pragma once
#include "Shape.h"
class Rect :
    public Shape
{
public:
    Rect() = default;
    ~Rect() override = default;
    void Paint(QPainter& painter) override;
};

