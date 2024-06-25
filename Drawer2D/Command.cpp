#include "Command.h"
#include "CanvasWidget.h"
#include <qdebug.h>

// ##################### Command ##################################
void Command::save()
{
    m_pMem = m_pCanvas->CreateMemento();
}

void Command::undo()
{
    m_pMem->restore();
    m_pCanvas->update();
}

void Command::redo()
{
    m_pMem->restore();
    m_pCanvas->update();
}


// ##################### Draw ##################################

void DrawCommand::execute()
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