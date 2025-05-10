#pragma once
#include <vector>
#include <algorithm>
#include <stdexcept>

class ArrayUtils {
public:
    static void fillArray(int* arr, int size, int min, int max);
    static void printArray(const int* arr, int size);
    static double calculateMean(const int* arr, int size);
    static int countElementsAboveMean(const int* arr, int size, double mean);
    static std::vector<int> getElementsAboveMean(const int* arr, int size, double mean);
    static int findMaximum(int a, int b, int c);
private:
    static void validateArrayParams(int size, int min, int max);
};
