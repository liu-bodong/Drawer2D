#pragma once
#include <memory>
#include <qlist.h>

class CanvasWidget;
class Item;

class Memento
{
public:
    explicit Memento(CanvasWidget* canvasWidget);

    void restore();

private:
    CanvasWidget* m_canvas;
    QList<std::shared_ptr<Item>> m_shapes;
};