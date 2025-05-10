#include "logger.h"
#include <iostream>

std::ofstream Logger::logFile;

void Logger::init(const std::string& filename) {
    logFile.open(filename, std::ios::app);
    if (!logFile.is_open()) {
        throw std::runtime_error("Unable to open log file");
    }
}

void Logger::log(const std::string& message, const std::string& level) {
    logFile << getTimestamp() << " [" << level << "] " << message << std::endl;
}

void Logger::error(const std::string& message) {
    log(message, "ERROR");
}

std::string Logger::getTimestamp() {
    time_t now = time(0);
    char buf[26];
    ctime_s(buf, sizeof(buf), &now);
    std::string ts(buf);
    return ts.substr(0, ts.length() - 1);
}
