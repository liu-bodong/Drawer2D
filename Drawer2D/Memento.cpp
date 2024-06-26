#include "Memento.h"
#include "CanvasWidget.h"


Memento::Memento(CanvasWidget* canvasWidget) : m_canvas(canvasWidget)
{
    m_shapes = m_canvas->GetShapes();
}

void Memento::Restore()
{
    m_canvas->SetCurVer(m_shapes);
}