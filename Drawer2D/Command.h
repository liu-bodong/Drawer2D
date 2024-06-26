#pragma once
#include "CanvasWidget.h"
#include "Memento.h"

class Command
{
protected:
    CanvasWidget* m_pCanvas;
    Memento* m_pMem;

public:
    explicit Command(CanvasWidget* canvas) : m_pCanvas(canvas) {};
    virtual ~Command() = default;
    virtual void execute() = 0;

    virtual void undo()
    {
        m_pMem->Restore();
        m_pCanvas->update();
    }

    virtual void redo()
    {
        m_pMem->Restore();
        m_pCanvas->update();
    }

    void save() { m_pMem = m_pCanvas->CreateMemento(); }
};

class DrawLineCommand : public Command
{
public:
    using Command::Command;
    void execute() override;
    void draw
};

class DrawRectCommand : public Command
{
public:
    using Command::Command;
    void execute() override;
};

class DrawEllipseCommand : public Command
{
public:
    using Command::Command;
    void execute() override;
};

class DrawCircleCommand : public Command
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

