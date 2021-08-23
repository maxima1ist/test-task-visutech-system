#include "Exception.h"

const char* Exception::EXCEPTION_MESSAGE = "Program failed!\nSee details description in \'messages.log\' file.";

const char* Exception::what() const noexcept {
    return EXCEPTION_MESSAGE;
}