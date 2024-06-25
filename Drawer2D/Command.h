#pragma once
#include <qstack.h>
#include <qundostack.h>
#include "CanvasWidget.h"
#include "Memento.h"
#include <stack>

class Command : public QUndoCommand
{
public:
    CanvasWidget* m_canvas;
    std::stack<Memento*> m_undoStack;
    std::stack<Memento*> m_redoStack;

public:
    explicit Command(CanvasWidget* canvas) : m_canvas(canvas) {}
    ~Command() override = default;
    virtual void execute() = 0;

    void undo() override;
    void redo() override;

    void save();
};

class DrawCommand : public Command
{
public:
    using Command::Command;
    void execute() override;
};

class ClearCommand : public Command
{
public:
    using Command::Command;
    void execute() override;
};

