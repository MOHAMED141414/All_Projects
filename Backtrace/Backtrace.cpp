#include <bits/stdc++.h>
#include "backtrace.hpp"

std::queue<std::string> backtrace::functions{};

backtrace::backtrace(std::string function, int line) : Function_Name(function), Entry_Line(line)
{
    std::cout << "Enter to [ " << function << " ] at line " << line << std::endl;
    functions.push(function);
}

backtrace::~backtrace()
{ }

void backtrace::print()
{
    std::queue<std::string> temp;
    temp = functions;
    int counter = 0;
    if (temp.empty())
    {
        std::cout << "Queue is empty " << std::endl;
        return;
    }
    while (!temp.empty())
    {
        std::cout << counter++ << "- " << temp.front() << std::endl;
        temp.pop();
    }
    std::cout << "Backtrace is finished" << std::endl;
}

void backtrace::exit(int line)
{
    std::cout << "Exit from [ " << Function_Name << " ] at line " << line << std::endl;
}


void backtrace::clear_queue(void)
{
    while (!functions.empty())
    {
        functions.pop();
    }
}
