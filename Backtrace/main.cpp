#include <bits/stdc++.h>
#include "backtrace.hpp"

void simpleFunction()
{
    EnterFn;  
    std::cout << "Inside simpleFunction" << std::endl;
    ExitFn;   
}

int main()
{
    EnterFn;  
    simpleFunction();  
    ExitFn;   

    return 0;
}