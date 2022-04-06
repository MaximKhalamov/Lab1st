#include "stackException.h"


StackException::StackException(std::string exceptionName, std::string exceptionInfo) {
    this->exceptionName = exceptionName;
    this->exceptionInfo = exceptionInfo;
}

std::string StackException::getExceptionName() { return exceptionName; }

std::string StackException::getExceptionInfo() { return exceptionInfo; }