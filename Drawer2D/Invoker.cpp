#include "Invoker.h"
#include <qdebug.h>

void Invoker::DoCommand(Command* curCommand)
{
    qDebug() << "Invoke Do";
    curCommand->execute();
    m_undoStack.push(curCommand);
    m_redoStack.clear();
    qDebug() << "Invoker stack count is: " << m_undoStack.count();
}

void Invoker::UndoCommand()
{
    qDebug() << "Invoke Undo 1";
    if (!m_undoStack.isEmpty())
    {
        qDebug() << "Invoke Undo";
        auto curCommand = m_undoStack.pop();
        curCommand->undo();
        m_redoStack.push(curCommand);
    }
}

void Invoker::RedoCommand()
{
    if (!m_redoStack.isEmpty())
    {
        qDebug() << "Invoke Redo";
        auto curCommand = m_redoStack.pop();
        curCommand->redo();
        m_undoStack.push(curCommand);
    }
}

