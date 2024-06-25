#include "Command.h"
#include "CanvasWidget.h"
#include <qdebug.h>

// ##################### Command ##################################
void Command::save()
{
    qDebug() << "Point 2 Command stack count is: " << m_undoStack.size();

    auto m = m_canvas->CreateMemento();
    qDebug() << "Memento is " << m;
    // m_redoStack.clear();
    m_undoStack.push(m);

    qDebug() << "Point 3 Command stack count is: " << m_undoStack.size();
    qDebug() << "Saved";
}

void Command::undo()
{
    if (!m_undoStack.empty())
    {
        qDebug() << "Undo";
        Memento* m = m_undoStack.top();
        m_undoStack.pop();
        m_redoStack.push(m);
        m->restore();
    }
}

void Command::redo()
{
    if (!m_redoStack.empty())
    {
        qDebug() << "Redo";
        Memento* m = m_redoStack.top();
        m_redoStack.pop();
        m_undoStack.push(m);
        m->restore();
    }
}


// ##################### Draw ##################################

void DrawCommand::execute()
{
    qDebug() << "Draw";
    qDebug() << "Point 1 Command stack count is: " << m_undoStack.size();
    save();
    qDebug() << "Point 4 Command stack count is: " << m_undoStack.size();
    //auto m = m_canvas->CreateMemento();
    //m_undoStack.push(m);
    qDebug() << "Is Command stack empty? " << (m_undoStack.empty());
}

// ##################### Clear ##################################

void ClearCommand::execute()
{
    m_canvas->Clear();
    m_canvas->update();
}