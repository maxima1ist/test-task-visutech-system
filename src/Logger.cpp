#include "Logger.h"

#include "ConstantStrings.h"

Logger::Logger(const string& userName) : logFile(ofstream("messages.log")) {
    log(Tags::INFO, "hello, " + userName);
}

Logger::~Logger() {
    log(Tags::INFO, "goodbye");
}

void Logger::log(const string& tag, string&& message) {
    logFile << tag << " : " << std::forward<string>(message) << '\n';
}
