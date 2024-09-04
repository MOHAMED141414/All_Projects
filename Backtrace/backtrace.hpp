#ifndef BACKTRACE_HPP
#define BACKTRACE_HPP


#include <bits/stdc++.h>

class backtrace;

#define EnterFn backtrace b1(__FUNCTION__, __LINE__)
#define ExitFn b1.exit(__LINE__)
#define PRINT_BACKtrace b1.print()
#define CLEAR_QUEUE b1.clear_queue()

class backtrace
{
private:
    std::string Function_Name;
    int Entry_Line; 
    static std::queue<std::string> functions;

public:
    backtrace() = default;
    backtrace(std::string function, int line); 
    ~backtrace();
    void exit(int line); 
    void print();
    void clear_queue();
};

#endif // BACKTRACE_HPP
