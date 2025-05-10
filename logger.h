#pragma once
#include <string>
#include <fstream>
#include <ctime>

class Logger {
public:
    static void init(const std::string& filename = "program.log");
    static void log(const std::string& message, const std::string& level = "INFO");
    static void error(const std::string& message);
private:
    static std::ofstream logFile;
    static std::string getTimestamp();
};
