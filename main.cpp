#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
#include <vector>
#include <string>
#include "logger.h"
#include "file_handler.h"
#include "array_utils.h"

#ifdef _WIN32
  #define CLEAR_CMD "cls"
#else
  #define CLEAR_CMD "clear"
#endif

// ANSI color codes
const std::string RESET  = "\033[0m";
const std::string RED    = "\033[31m";
const std::string GREEN  = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string CYAN   = "\033[36m";
const std::string WHITE  = "\033[97m";

// Configuration
const int DEFAULT_SIZE = 10;
const int MIN_VALUE    = 0;
const int MAX_VALUE    = 100;

// Helper prototypes
void clearScreen();
void pause();
void displayHeader(const std::string &title);
void displayMenu();
int getInt(const std::string &prompt, int min, int max);
void optionGenerate();
void optionView();
void optionMean();
void optionAboveMean();
void optionSaveLoad();
void optionAbout();

// Global array storage
static int g_array[DEFAULT_SIZE];
static int g_size = DEFAULT_SIZE;

int main() {
    Logger::init("array_system.log");
    Logger::log("Program started");

    while (true) {
        clearScreen();
        displayMenu();
        int choice = getInt("Select option (0-6): ", 0, 6);
        switch (choice) {
            case 1: optionGenerate();   break;
            case 2: optionView();       break;
            case 3: optionMean();       break;
            case 4: optionAboveMean();  break;
            case 5: optionSaveLoad();   break;
            case 6: optionAbout();      break;
            case 0:
                Logger::log("Program exiting");
                return 0;
        }
        pause();
    }
}

void clearScreen() {
    std::system(CLEAR_CMD);
}

void pause() {
    std::cout << YELLOW << "\nPress any key to continue..." << RESET;
    _getch();
}

void displayHeader(const std::string &title) {
    clearScreen();
    std::cout << CYAN
              << R"(
   ___   ____   _____  ____
  / _ \ / ___| | ____|/ ___|
 | | | | |  _  |  _|  \___ \
 | |_| | |_| | | |___  ___) |
  \__\_\\____| |_____|____/
)" << RESET
              << WHITE << "\n    " << title << "\n\n" << RESET;
}

void displayMenu() {
    displayHeader("ARRAY SYSTEM");
    std::cout << CYAN
              << "+----------------------------------+\n"
              << "|          MAIN MENU               |\n"
              << "+----------------------------------+\n"
              << RESET;
    std::cout << GREEN
              << " 1) Generate random array\n"
              << " 2) View array contents\n"
              << " 3) Calculate mean\n"
              << " 4) Count above mean\n"
              << " 5) Save/load from file\n"
              << " 6) About author\n"
              << " 0) Exit\n"
              << RESET;
}

int getInt(const std::string &prompt, int min, int max) {
    int v;
    while (true) {
        std::cout << YELLOW << prompt << RESET;
        if (std::cin >> v && v >= min && v <= max) {
            return v;
        }
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << RED << "Invalid input, enter " << min << "-" << max << "." << RESET << "\n";
        Logger::error("Invalid menu input");
    }
}

void optionGenerate() {
    displayHeader("GENERATE ARRAY");
    ArrayUtils::fillArray(g_array, g_size, MIN_VALUE, MAX_VALUE);
    std::cout << GREEN << "Array generated with " << g_size << " elements.\n" << RESET;
    Logger::log("Array generated");
}

void optionView() {
    displayHeader("VIEW ARRAY");
    std::cout << WHITE;
    ArrayUtils::printArray(g_array, g_size);
    std::cout << RESET;
    Logger::log("Array viewed");
}

void optionMean() {
    displayHeader("CALCULATE MEAN");
    double mean = ArrayUtils::calculateMean(g_array, g_size);
    std::cout << GREEN << "Mean value: " << std::fixed << std::setprecision(2) << mean << "\n" << RESET;
    Logger::log("Mean calculated: " + std::to_string(mean));
}

void optionAboveMean() {
    displayHeader("COUNT ABOVE MEAN");
    double mean = ArrayUtils::calculateMean(g_array, g_size);
    int count = ArrayUtils::countElementsAboveMean(g_array, g_size, mean);
    std::cout << GREEN << "Elements > mean (" << mean << "): " << count << "\n" << RESET;
    Logger::log("Count above mean: " + std::to_string(count));
}

void optionSaveLoad() {
    displayHeader("SAVE / LOAD");
    std::cout << CYAN
              << "1) Save array to file\n"
              << "2) Load array from file\n"
              << RESET;
    int c = getInt("Choice (1-2): ", 1, 2);
    if (c == 1) {
        FileHandler::saveArrayToFile(g_array, g_size, "array_data.txt");
        std::cout << GREEN << "Array saved to array_data.txt\n" << RESET;
        Logger::log("Array saved");
    } else {
        auto v = FileHandler::loadArrayFromFile("array_data.txt");
        if (!v.empty() && (int)v.size() == g_size) {
            for (int i = 0; i < g_size; ++i) g_array[i] = v[i];
            std::cout << GREEN << "Array loaded from file\n" << RESET;
            Logger::log("Array loaded");
        } else {
            std::cout << RED << "Failed to load or incorrect size\n" << RESET;
            Logger::error("Load failed or size mismatch");
        }
    }
}

void optionAbout() {
    displayHeader("ABOUT AUTHOR");
    std::cout << WHITE
              << "Adrian Lesniak\n"
              << "C++ Developer & Enthusiast\n"
              << "This program demonstrates array handling,\n"
              << "statistics, and file I/O with a colorful\n"
              << "ASCII interface.\n\n"
              << RESET;
    Logger::log("Displayed about author");
}
