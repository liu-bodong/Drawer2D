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


    Command* p_curCommand = nullptr;
    QStack<Command*> m_undoStack;
    QStack<Command*> m_redoStack;
    int pos = 0;
};

