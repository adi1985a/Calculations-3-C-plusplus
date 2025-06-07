# 📊🔢 ArrayInsight Pro: C++ Array Analysis Toolkit 📈
_A C++ console application for generating, analyzing, and managing arrays with statistical calculations, file I/O, and cross-platform colored output._

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C++](https://img.shields.io/badge/Language-C%2B%2B%2011%2B-blue.svg)](https://isocpp.org/)
[![Platform: Cross-platform](https://img.shields.io/badge/Platform-Cross--platform-lightgrey.svg)]()

## 📋 Table of Contents
1. [Overview](#-overview)
2. [Key Features](#-key-features)
3. [Screenshots](#-screenshots)
4. [System Requirements](#-system-requirements)
5. [Core Custom Headers (`array_utils.h`, `logger.h`, `file_handler.h`)](#-core-custom-headers-array_utilsh-loggerh-file_handlerh)
6. [Installation and Setup](#️-installation-and-setup)
7. [Usage Guide](#️-usage-guide)
8. [File Structure & Data Persistence](#-file-structure--data-persistence)
9. [Technical Notes](#-technical-notes)
10. [Contributing](#-contributing)
11. [License](#-license)
12. [Contact](#-contact)

## 📄 Overview

**ArrayInsight Pro**, developed by Adrian Lesniak, is an interactive C++ console program for handling and analyzing a one-dimensional integer array. It allows you to generate a random array, view its contents, calculate the arithmetic mean, count elements above the mean, and save/load the array from a file. The program features a colorful menu, input validation, and event logging.

![Demo GIF](screenshots/1.gif)

## ✨ Key Features

- 🔢 **Array Generation & Display**:
  - Generates a random array of default size 10 (value range: 0–100).
  - Displays the array contents in a readable, colored format.
- 📊 **Statistical Analysis**:
  - Calculates and displays the arithmetic mean of the array.
  - Counts and displays the number of elements greater than the mean.
- 💾 **File Operations**:
  - Saves the current array to `array_data.txt`.
  - Loads an array from file (with size validation).
- 🖥️ **Interactive Console Menu**:
  - ASCII art header, clear menu (generate, view, mean, above mean, save/load, about, exit).
  - Colorful ANSI output (works on Windows 10+, Linux, macOS).
- 🛠️ **Utility Functions**:
  - Clears the screen (`cls`/`clear`).
  - Pauses and waits for any key.
- ✍️ **Logging**:
  - Logs events (generation, file operations, errors) to a log file.
- ⚙️ **Robustness**:
  - Main loop continues until user chooses to exit.
  - Strong input validation.

## 🖼️ Screenshots

_Screenshots showing the menu, generation, viewing, statistics, file operations, and about screen._

<p align="center">
  <img src="screenshots/1.jpg" width="300"/>
  <img src="screenshots/2.jpg" width="300"/>
  <img src="screenshots/3.jpg" width="300"/>
  <img src="screenshots/4.jpg" width="300"/>
  <img src="screenshots/5.jpg" width="300"/>
  <img src="screenshots/6.jpg" width="300"/>
</p>

## ⚙️ System Requirements

- **Operating System**: Windows 10+, Linux, or macOS (ANSI terminal).
- **C++ Compiler**: C++11+ (g++, clang++, MSVC).
- **Libraries**: `<iostream>`, `<iomanip>`, `<vector>`, `<cstdlib>`, `<conio.h>`, `<string>`, `<fstream>`.
- **User headers**: `array_utils.h`, `logger.h`, `file_handler.h` (you must provide these).
- **Write permissions**: for `array_data.txt` and the log file.

## 🧩 Core Custom Headers (`array_utils.h`, `logger.h`, `file_handler.h`)

- **`array_utils.h`**: Array operations.
  - Example: `fillArray(int arr[], int size, int minVal, int maxVal)`, `printArray(const int arr[], int size)`, `double calculateMean(const int arr[], int size)`, `int countElementsAboveMean(const int arr[], int size, double mean)`.
- **`logger.h`**: Logging.
  - Example: `Logger::log(const std::string&)`, `Logger::error(const std::string&)`, `Logger::init(const std::string&)`.
- **`file_handler.h`**: File operations.
  - Example: `FileHandler::saveArrayToFile(const int arr[], int size, const std::string&)`, `std::vector<int> FileHandler::loadArrayFromFile(const std::string&)`.

## 🛠️ Installation and Setup

1. **Clone the repository**:
    ```bash
    git clone <repository-url>
    cd <repository-directory>
    ```
2. **Add header and implementation files**:
    - Add `array_utils.h`, `logger.h`, `file_handler.h` and their `.cpp` files.
3. **Main code**:
    - Save your main code as `main.cpp`.
4. **Compile**:
    ```bash
    g++ main.cpp array_utils.cpp logger.cpp file_handler.cpp -o array_analysis -std=c++11
    ```
5. **Run the program**:
    - Windows: `.\array_analysis.exe`
    - Linux/macOS: `./array_analysis`

## 💡 Usage Guide

1. Compile and run the program.
2. **Menu**:
    1. Generate random array
    2. View array contents
    3. Calculate mean
    4. Count above mean
    5. Save/load from file
    6. About author
    0. Exit
3. **Input**:
    - Select an option (0–6) and press Enter.
    - Invalid input triggers a message and logging.
4. **Output**:
    - Each operation displays a result and logs the event.
    - File operations use `array_data.txt`.
5. **Actions**:
    - After each operation, press any key to return to the menu.
    - Option `0` exits the program.

## 🗂️ File Structure & Data Persistence

- `main.cpp`: Main loop and menu handling.
- `array_utils.h` / `array_utils.cpp`: Array functions.
- `logger.h` / `logger.cpp`: Logging.
- `file_handler.h` / `file_handler.cpp`: File operations.
- `array_data.txt`: Array save/load.
- `[log_file_name].log`: Log file.
- `README.md`: Documentation.

## 📝 Technical Notes

- **Cross-platform UI**: Uses `system("cls")`/`system("clear")`, ANSI colors.
- **Modularity**: Logic separated into headers.
- **Input validation**: Strong validation for menu and data.
- **Logging**: All major events and errors are logged.

## 🤝 Contributing

Want to add features or fixes? Fork the repo, create a branch, commit, and open a Pull Request. Please keep code modular and well-commented.

## 📃 License

This project is licensed under the **MIT License**.

## 📧 Contact

Author: **Adrian Lesniak**  
Questions/feedback: open an issue or contact via the repository.

---
🔬 _Analyzing arrays, discovering patterns, one element at a time._
