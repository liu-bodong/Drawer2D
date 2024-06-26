#pragma once
#include "Shape.h"


class IEllipse :
    public Shape
{
public:
    IEllipse() = default;
    ~IEllipse() override = default;
    void Paint(QPainter& painter) override;
};



