#include "Invoker.h"
#include <qdebug.h>

void Invoker::DoCommand(Command* curCmd)
{
    curCmd->execute();
    m_undoStack.push(pLastCmd);
    m_redoStack.clear();
    pLastCmd = curCmd;
}

void Invoker::UndoCommand()
{
    if (!m_undoStack.isEmpty() && pLastCmd)
    {
        m_redoStack.push(pLastCmd);
        pLastCmd = m_undoStack.pop();
        if (pLastCmd) { pLastCmd->undo(); }
    }
}

void Invoker::RedoCommand()
{
    if (!m_redoStack.isEmpty())
    {
        m_undoStack.push(pLastCmd);
        pLastCmd = m_redoStack.pop();
        pLastCmd->redo();
    }
}

bool Invoker::UndoEmpty() const
{
    return m_undoStack.empty();
}

