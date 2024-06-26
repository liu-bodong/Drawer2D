#include "Line.h"
#include <qpainterpath.h>

void Line::Paint(QPainter& painter)
{
    auto path = QPainterPath(m_start);
    path.lineTo(m_end);
    painter.drawPath(path);
}