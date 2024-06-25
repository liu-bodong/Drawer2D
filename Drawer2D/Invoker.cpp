#include "Invoker.h"
#include <qdebug.h>

void Invoker::DoCommand(Command* curCommand)
{
    curCommand->execute();
    m_undoStack.push(curCommand);
    m_redoStack.clear();
    qDebug() << "Do: Undo stack size is: " << m_undoStack.size();
}

void Invoker::UndoCommand()
{
    if (!m_undoStack.isEmpty())
    {
        auto curCommand = m_undoStack.pop();
        curCommand->undo();
        m_redoStack.push(curCommand);
        qDebug() << "Undo: Undo stack size is: " << m_undoStack.size();
        qDebug() << "Undo: Redo stack size is: " << m_redoStack.size();
    }
}

void Invoker::RedoCommand()
{
    if (!m_redoStack.isEmpty())
    {
        auto curCommand = m_redoStack.pop();
        curCommand->redo();
        m_undoStack.push(curCommand);
        qDebug() << "Redo: Undo stack size is: " << m_undoStack.size();
        qDebug() << "Redo: Redo stack size is: " << m_redoStack.size();
    }
}

