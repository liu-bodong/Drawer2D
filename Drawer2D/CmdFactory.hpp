#pragma once
#include <string>
#include <map>
#include <functional>

class Command;

class CmdFactory
{
public:
    static CmdFactory& GetInstance(const std::string& name)
    {
        static CmdFactory m_instance;
        return m_instance;
    }

    static void Register(const std::string& name, std::function<Command* ()> func)
    {
        if (cmd_.contains(name))
        {
            return;
        }
        else
        {
            cmd_.try_emplace(name, func);
        }
    }

    static Command* Create(const std::string& name)
    {
        auto it = cmd_.find(name);
        if (it != cmd_.end())
        {
            return it->second();
        }
        else
        {
            return nullptr;
        }
    }

private:
    static std::map<std::string, std::function<Command* ()>> cmd_;
    CmdFactory() = default;
    ~CmdFactory() = default;
    CmdFactory(const CmdFactory&) = delete;
    CmdFactory(CmdFactory&&) = delete;
};

std::map<std::string, std::function<Command* ()>> CmdFactory::cmd_;