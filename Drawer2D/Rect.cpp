#include "Rect.h"
#include <qpainterpath.h>
#include <qrect.h>

void Rect::Paint(QPainter& painter)
{
    auto path = QPainterPath();
    path.addRect(QRect(m_start, m_end));
    painter.drawPath(path);
}