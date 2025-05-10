#include "file_handler.h"
#include <fstream>
#include <stdexcept>

void FileHandler::validateFile(const std::string& filename) {
    if (filename.empty()) {
        throw std::invalid_argument("Filename cannot be empty");
    }
}

std::vector<int> FileHandler::loadArrayFromFile(const std::string& filename) {
    validateFile(filename);
    std::vector<int> result;
    std::ifstream file(filename);
    if (file) {
        int value;
        while (file >> value) {
            result.push_back(value);
        }
    }
    return result;
}

void FileHandler::saveResults(const std::string& filename, double mean, int count) {
    validateFile(filename);
    std::ofstream file(filename);
    if (file) {
        file << mean << " " << count;
    }
}

void FileHandler::saveArrayToFile(const int* arr, int size, const std::string& filename) {
    validateFile(filename);
    std::ofstream file(filename);
    if (file) {
        for (int i = 0; i < size; i++) {
            file << arr[i] << " ";
        }
    }
}
