#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <string>

using std::string;
using std::ofstream;

class Logger {

public:
    Logger(const string& userName);
    
    ~Logger();
    
    void log(const string& tag, string&& message);

private:
    ofstream logFile;
};

#endif //LOGGER_H
