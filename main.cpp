#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <limits>
#include "array_utils.h"
#include "logger.h"
#include "file_handler.h"

#define N 12

// Color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37;1m"

/*
Array Analysis Program v1.0
---------------------------
This program provides the following functionalities:

1. Generate Arrays:
   - Creates three arrays (X, Y, Z) with random numbers
   - User can specify the range for random numbers

2. Display Arrays:
   - Shows all three arrays in a formatted way
   - Numbers are displayed in an organized layout

3. Calculate Statistics:
   - Computes arithmetic mean of array X
   - Counts elements above the mean
   - Displays statistical results

4. Save Results:
   - Saves statistical results to a file
   - File name: "results.txt"

5. Load Previous Results:
   - Loads previously saved array data
   - Displays loaded data from "saved_array.txt"

0. Exit Program:
   - Safely closes the program
   - Saves log information

Navigation: Press Enter to return to main menu after each operation
*/

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void displayHeader() {
    clearScreen();
    std::cout << WHITE << "\n"
              << "+------------------------------------------------+\n"
              << "|              Array Analysis Program             |\n"
              << "|                                                |\n"
              << "| " << CYAN << "Description:" << WHITE << "                                   |\n"
              << "| " << CYAN << "This program handles operations on arrays:" << WHITE << "     |\n"
              << "| " << CYAN << "- Generates random numbers" << WHITE << "                     |\n"
              << "| " << CYAN << "- Calculates statistics" << WHITE << "                        |\n"
              << "| " << CYAN << "- Saves and loads results" << WHITE << "                      |\n"
              << "+------------------------------------------------+\n"
              << RESET << std::endl;
}

void waitForEnter() {
    std::cout << GREEN << "\nPress Enter to return to menu..." << RESET;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    clearScreen();
}

void displayMenu() {
    std::cout << GREEN
              << "\nAvailable options:\n"
              << "\n1. Generate new arrays"
              << " - Fill X, Y, Z arrays with random numbers"
              << "\n2. Display arrays"
              << " - Show content of all arrays"
              << "\n3. Calculate statistics"
              << " - Calculate mean and count elements above mean"
              << "\n4. Save results"
              << " - Save current results to file"
              << "\n5. Load previous results"
              << "\n0. Exit program"
              << YELLOW << "\n\nEnter your choice (0-5): " << RESET;
}

int main() {
    try {
        Logger::init();
        Logger::log("Program started");

        int X[N], Y[N], Z[N];  // Removed unused Q array
        int choice;
        double mean = 0;
        int countAboveMean = 0;

        do {
            displayHeader();
            displayMenu();
            
            if (!(std::cin >> choice)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << RED << "\nInvalid input! Please enter a number." << RESET;
                waitForEnter();
                continue;
            }

            clearScreen();
            switch(choice) {
                case 1: {
                    std::cout << WHITE << "\n=== Generating Arrays ===" << RESET << "\n\n";
                    int p, k;
                    std::cout << YELLOW << "Enter range <p,k>: " << RESET;
                    std::cin >> p >> k;
                    
                    ArrayUtils::fillArray(X, N, p, k);
                    ArrayUtils::fillArray(Y, N, p, k);
                    ArrayUtils::fillArray(Z, N, p, k);
                    Logger::log("Arrays generated successfully");
                    std::cout << GREEN << "\nArrays generated successfully!" << RESET;
                    waitForEnter();
                    break;
                }
                case 2: {
                    std::cout << WHITE << "\n=== Displaying Arrays ===" << RESET << "\n\n";
                    std::cout << WHITE << "\nArray X: " << RESET;
                    ArrayUtils::printArray(X, N);
                    std::cout << WHITE << "Array Y: " << RESET;
                    ArrayUtils::printArray(Y, N);
                    std::cout << WHITE << "Array Z: " << RESET;
                    ArrayUtils::printArray(Z, N);
                    waitForEnter();
                    break;
                }
                case 3: {
                    std::cout << WHITE << "\n=== Calculating Statistics ===" << RESET << "\n\n";
                    mean = ArrayUtils::calculateMean(X, N);
                    countAboveMean = ArrayUtils::countElementsAboveMean(X, N, mean);
                    std::cout << "Mean: " << mean << "\nElements above mean: " << countAboveMean << std::endl;
                    waitForEnter();
                    break;
                }
                case 4: {
                    std::cout << WHITE << "\n=== Saving Results ===" << RESET << "\n\n";
                    FileHandler::saveResults("results.txt", mean, countAboveMean);
                    Logger::log("Results saved to file");
                    std::cout << GREEN << "\nResults saved successfully!" << RESET;
                    waitForEnter();
                    break;
                }
                case 5: {
                    std::cout << WHITE << "\n=== Loading Previous Results ===" << RESET << "\n\n";
                    std::vector<int> loaded = FileHandler::loadArrayFromFile("saved_array.txt");
                    std::cout << "Loaded array: ";
                    for (int val : loaded) std::cout << val << " ";
                    std::cout << std::endl;
                    waitForEnter();
                    break;
                }
                case 0:
                    std::cout << GREEN << "\nThank you for using Array Analysis Program!\n" << RESET;
                    waitForEnter();
                    break;
                default:
                    std::cout << RED << "\nInvalid choice! Please enter a number between 0 and 5." << RESET;
                    waitForEnter();
            }
        } while (choice != 0);

        Logger::log("Program ended normally");
    }
    catch (const std::exception& e) {
        Logger::error(e.what());
        std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
        return 1;
    }

    return 0;
}
