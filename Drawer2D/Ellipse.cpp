#include "Ellipse.h"
#include <qpainterpath.h>
#include <qrect.h>

void IEllipse::Paint(QPainter& painter)
{
    auto path = QPainterPath();
    path.addEllipse(QRect(m_start, m_end));
    painter.drawPath(path);
}