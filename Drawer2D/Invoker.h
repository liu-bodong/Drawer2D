#pragma once
#include "Command.h"

class Command;

class Invoker
{
public:
    Invoker() = default;
    void DoCommand(Command* curCommand);
    void UndoCommand();
    void RedoCommand();
    bool UndoEmpty() const;
    Command* pLastCmd;
    QStack<Command*> m_undoStack;
    QStack<Command*> m_redoStack;
};

