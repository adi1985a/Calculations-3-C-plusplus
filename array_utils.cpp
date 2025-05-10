#include "array_utils.h"
#include <random>
#include <iostream>

void ArrayUtils::validateArrayParams(int size, int min, int max) {
    if (size <= 0) throw std::invalid_argument("Array size must be positive");
    if (min >= max) throw std::invalid_argument("Min must be less than max");
}

void ArrayUtils::fillArray(int* arr, int size, int min, int max) {
    validateArrayParams(size, min, max);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    
    for (int i = 0; i < size; i++) {
        arr[i] = dis(gen);
    }
}

void ArrayUtils::printArray(const int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

double ArrayUtils::calculateMean(const int* arr, int size) {
    if (size <= 0) return 0.0;
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

int ArrayUtils::countElementsAboveMean(const int* arr, int size, double mean) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > mean) count++;
    }
    return count;
}
