#pragma once

#include <memory>
#include "Shape.h"


class Item
{
private:
    std::shared_ptr<Shape> m_shape;
    QPen m_pen;

public:
    Item(std::shared_ptr<Shape> shape, QPen pen)
        : m_shape(shape), m_pen(pen) {}

    ~Item() = default;

    std::shared_ptr<Shape> getShape() const
    {
        return m_shape;
    }

    void setCurShape(std::shared_ptr<Shape> shape)
    {
        m_shape = shape;
    }

    QPen getPen() const
    {
        return m_pen;
    }

    void setPen(QPen pen)
    {
        m_pen = pen;
    }
};
