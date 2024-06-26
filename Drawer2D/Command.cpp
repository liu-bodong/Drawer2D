#include "Command.h"
#include "CanvasWidget.h"
#include <qdebug.h>
// ##################### Draw ##################################

void DrawLineCommand::execute()
{
    save();
}

void DrawRectCommand::execute()
{
    save();
}

void DrawEllipseCommand::execute()
{
    save();
}

void DrawCircleCommand::execute()
{
    save();
}

// ##################### Clear ##################################

void ClearCommand::execute()
{
    m_pCanvas->Clear();
    save();
    m_pCanvas->update();
}