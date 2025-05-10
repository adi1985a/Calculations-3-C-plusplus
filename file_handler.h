#pragma once
#include <string>
#include <vector>

class FileHandler {
public:
    static void saveArrayToFile(const int* arr, int size, const std::string& filename);
    static std::vector<int> loadArrayFromFile(const std::string& filename);
    static void saveResults(const std::string& filename, double mean, int count);
private:
    static void validateFile(const std::string& filename);
};
