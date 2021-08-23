#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>

class Exception : public std::exception {
public:
    static const char* EXCEPTION_MESSAGE;
    
    const char* what() const noexcept override;
};

#endif //EXCEPTION_H
