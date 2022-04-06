#ifndef STACKEXCEPTION_H
#define STACKEXCEPTION_H
#include <string>
#include <iostream>

class StackException{
    private:
        std::string exceptionName;
        std::string exceptionInfo;
    public:
        StackException(std::string exceptionName, std::string exceptionInfo);
        std::string getExceptionName();
        std::string getExceptionInfo();
};

#endif // !STACKEXCEPTION_H
