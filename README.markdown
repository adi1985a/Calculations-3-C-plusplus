# 📊🔢 ArrayInsight Pro: C++ Array Analysis Toolkit 📈
_A C++ console application for generating, analyzing, and managing arrays with statistical calculations, file I/O, and cross-platform colored output._

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C++](https://img.shields.io/badge/Language-C%2B%2B%2011%2B-blue.svg)](https://isocpp.org/)
[![Platform: Cross-platform](https://img.shields.io/badge/Platform-Cross--platform-lightgrey.svg)]()

## 📋 Table of Contents
1.  [Overview](#-overview)
2.  [Key Features](#-key-features)
3.  [Screenshots](#-screenshots)
4.  [System Requirements](#-system-requirements)
5.  [Core Custom Headers (`array_utils.h`, `logger.h`, `file_handler.h`)](#-core-custom-headers-array_utilsh-loggerh-file_handlerh)
6.  [Installation and Setup](#️-installation-and-setup)
7.  [Usage Guide](#️-usage-guide)
8.  [File Structure & Data Persistence](#-file-structure--data-persistence)
9.  [Technical Notes](#-technical-notes)
10. [Contributing](#-contributing)
11. [License](#-license)
12. [Contact](#-contact)

## 📄 Overview

**ArrayInsight Pro**, developed by Adrian Lesniak, is a C++ console application designed for comprehensive analysis of one-dimensional arrays. The program allows users to generate three distinct arrays (X, Y, Z), each containing 12 elements filled with random numbers within a user-defined range. It provides functionalities to display these arrays, calculate the arithmetic mean of array X, and count how many elements in array X are above this mean. Furthermore, it supports saving key results (mean and count) to `results.txt` and saving/loading an entire array (typically X) to/from `saved_array.txt`. The application features a user-friendly, menu-driven interface with **cross-platform colored output** (using ANSI escape codes), robust input validation, and event/error logging facilitated by user-provided header files (`array_utils.h`, `logger.h`, `file_handler.h`).

## ✨ Key Features

*   🔢 **Array Generation & Display**:
    *   `ArrayUtils::fillArray`: Populates three 12-element arrays (X, Y, Z) with random numbers based on a user-specified lower (`p`) and upper (`k`) bound.
    *   `ArrayUtils::printArray`: Neatly displays the contents of the arrays in a formatted layout.
*   📊 **Statistical Analysis (for Array X)**:
    *   `ArrayUtils::calculateMean`: Computes and returns the arithmetic mean of the elements in array X.
    *   `ArrayUtils::countElementsAboveMean`: Counts and returns the number of elements in array X that are greater than its calculated mean.
*   💾 **File Input/Output**:
    *   `FileHandler::saveResults`: Saves the calculated mean and count of elements above the mean for array X to `results.txt`.
    *   `FileHandler::loadArrayFromFile`: Loads array data from `saved_array.txt` into one of the program's arrays (e.g., array X).
    *   `FileHandler::saveArrayToFile` (implied): A corresponding function to save an array to `saved_array.txt` would be necessary for the load functionality to be complete.
*   🖥️ **Interactive Console Interface**:
    *   `displayHeader`: Shows an engaging program title and description, possibly with ASCII art.
    *   `displayMenu`: Presents a clear, numbered list of options: generate arrays, display arrays, calculate statistics, save results/array, load array, and exit.
    *   **Cross-Platform Colored Output**: Utilizes ANSI escape codes (via helper functions in `logger.h` or `array_utils.h`) for colored text output (red, green, yellow, cyan, white) on compatible terminals.
*   🛠️ **Utility Functions**:
    *   `clearScreen`: Clears the console window (`cls` for Windows, `clear` for Linux/macOS).
    *   `waitForEnter`: Pauses program execution, prompting the user to press Enter to continue or return to the menu.
*   ✍️ **Logging**:
    *   **Logger**: (via `logger.h`) Logs significant program events (e.g., array generation, file operations) and any errors encountered to a log file.
*   ⚙️ **Robust Operation**:
    *   Main program loop continues until the user chooses to exit (option 0).
    *   Includes input validation and C++ exception handling for managing invalid user inputs or operational issues.

## 🖼️ Screenshots

**Coming soon!**

_This section will be updated with screenshots showcasing the main menu, array generation prompts, array displays, statistical outputs, and examples of `results.txt` and `saved_array.txt`._

## ⚙️ System Requirements

*   **Operating System**: Any OS supporting a C++11 (or later) compiler and an ANSI-compatible terminal for colored output (e.g., Windows 10+ Terminal, Linux terminals, macOS Terminal).
*   **C++ Compiler**: A C++ compiler supporting C++11 or later (e.g., g++, clang++, MSVC).
*   **Standard C++ Libraries**: `<iostream>`, `<iomanip>`, `<vector>` (if arrays are `std::vector`), `<random>` (for better random numbers than `rand()`), `<numeric>` (for `std::accumulate`), `<algorithm>` (for `std::count_if`), `<stdexcept>`, `<limits>`, `<fstream>`, `<ctime>`.
*   📄 **Custom Header Files (User-Provided)**: This project **critically requires** `array_utils.h`, `logger.h`, and `file_handler.h`. **These files are not included in the repository and must be created by the user.** They should define necessary classes/functions for array manipulation, logging, and file operations. See "Core Custom Headers" and "Installation and Setup" for details.
*   **Write Permissions**: The application needs write permissions in its execution directory for `results.txt`, `saved_array.txt`, and the log file.

## 🧩 Core Custom Headers (`array_utils.h`, `logger.h`, `file_handler.h`)

These user-provided header files are essential for the program's functionality:

*   **`array_utils.h`**: Declares functions or a class (e.g., `ArrayUtils`) for array operations.
    *   Example Methods: `fillArray(int arr[], int size, int minVal, int maxVal)`, `printArray(const int arr[], int size)`, `double calculateMean(const int arr[], int size)`, `int countElementsAboveMean(const int arr[], int size, double mean)`.
    *   May also include console utilities like `clearScreen`, `waitForEnter` if not in a separate general utils header.
*   **`logger.h`**: Declares a `Logger` class or logging functions.
    *   Example Methods: `Logger::info(const std::string& message)`, `Logger::error(const std::string& message)`, `Logger::debug(const std::string& message)`.
    *   Manages writing timestamped entries to a log file.
*   **`file_handler.h`**: Declares a `FileHandler` class or file operation functions.
    *   Example Methods: `bool saveResults(const std::string& filePath, double mean, int count)`, `bool saveArrayToFile(const std::string& filePath, const int arr[], int size)`, `bool loadArrayFromFile(const std::string& filePath, int arr[], int size)`.

## 🛠️ Installation and Setup

1.  **Clone the Repository**:
    ```bash
    git clone <repository-url>
    cd <repository-directory>
    ```
    (Replace `<repository-url>` and `<repository-directory>` with your specific details)

2.  **Create Custom Header & Implementation Files**:
    *   Create `array_utils.h`, `logger.h`, and `file_handler.h` in the project directory with the necessary declarations.
    *   Create corresponding `.cpp` files (e.g., `array_utils.cpp`, `logger.cpp`, `file_handler.cpp`) with the implementations for the functions/classes declared in these headers.

3.  **Save Main Code**:
    Ensure your main application logic is saved as `array_analysis.cpp` in the project directory.

4.  **Compile the Program**:
    Open a terminal in the project directory.
    **Example using g++:**
    ```bash
    g++ array_analysis.cpp array_utils.cpp logger.cpp file_handler.cpp -o array_analysis -std=c++11
    ```
    *(This assumes separate `.cpp` files for your custom headers. Adjust the command if your structure differs, e.g., if some logic is header-only or combined differently. Add `-static-libgcc -static-libstdc++` on Windows with MinGW if desired for standalone executables).*

5.  **Run the Program**:
    *   On Windows: `.\array_analysis.exe` or `array_analysis.exe`
    *   On Linux/macOS: `./array_analysis` (ensure execute permissions: `chmod +x array_analysis`)

## 💡 Usage Guide

1.  Compile and run `array_analysis` as detailed above.
2.  **Interface**:
    *   The program will display a header, possibly with ASCII art, and then the main menu:
        1.  Generate new arrays (X, Y, Z)
        2.  Display arrays (X, Y, Z)
        3.  Calculate statistics for array X (Mean & Count Above Mean)
        4.  Save results (Mean & Count for X) to `results.txt`
        5.  Load array (e.g., X) from `saved_array.txt`
        0.  Exit
3.  **Input**:
    *   Select a menu option (0–5) by typing the number and pressing Enter.
    *   **For Option 1 (Generate Arrays)**: You will be prompted to enter the lower bound `p` and upper bound `k` for the random number range.
    *   Invalid inputs (e.g., non-numeric, `p > k`) will trigger error messages (logged) and prompt for re-entry.
4.  **Output**:
    *   **Option 1**: Confirmation message upon successful array generation.
    *   **Option 2**: Displays the contents of arrays X, Y, and Z (e.g., "Array X: 3 5 7 ...").
    *   **Option 3**: Shows the calculated arithmetic mean for array X and the count of its elements that are greater than this mean (e.g., "Mean of Array X: 6.50, Elements above mean: 4").
    *   **Option 4**: Confirmation message that results have been saved to `results.txt`.
    *   **Option 5**: Displays the array loaded from `saved_array.txt`, or an error message if loading failed.
    *   Errors encountered during operations are logged to the specified log file via `Logger::error`.
5.  **Actions**:
    *   After each operation and display of results, you will be prompted to press Enter to return to the main menu.
    *   Select option `0` from the main menu to exit the application.

## 🗂️ File Structure & Data Persistence

*   `array_analysis.cpp`: The main C++ source file containing the primary program loop, menu handling, and calls to utility/handler functions/classes.
*   `array_utils.h` / `array_utils.cpp`: (User-provided) Defines and implements array-specific utility functions.
*   `logger.h` / `logger.cpp`: (User-provided) Defines and implements logging functionalities.
*   `file_handler.h` / `file_handler.cpp`: (User-provided) Defines and implements functions/classes for saving and loading data to/from files.
*   `results.txt`: A plain text file where statistical results (mean of X, count above mean for X) are saved, typically appended with new entries.
*   `saved_array.txt`: A plain text file used to store the data of an array (e.g., array X) for later loading.
*   `[log_file_name].log`: A log file (name determined by `Logger` implementation) for recording program events and errors.
*   `README.md`: This documentation file.

## 📝 Technical Notes

*   **Cross-Platform UI**: The use of `clearScreen` with conditional compilation (`#ifdef _WIN32` for `system("cls")` vs. `system("clear")`) and ANSI escape codes for colors aims for a consistent visual experience across different operating systems with compatible terminals.
*   **Modularity via Headers**: The project's reliance on `array_utils.h`, `logger.h`, and `file_handler.h` promotes a modular design, separating concerns for array logic, logging, and file operations.
*   **Random Number Generation**: It's good practice to use C++11 `<random>` library for more robust and better-distributed random numbers than `rand()`. Ensure `srand()` is called once at the beginning of `main()` if using `rand()`.
*   **Input Validation**: Robust input validation using C++ stream states (`std::cin.fail()`, `clear()`, `ignore()`) and potentially `try-catch` blocks for `std::stoi` or `std::stod` conversions is crucial.
*   **Error Logging**: The `Logger` component is vital for debugging and understanding program flow, especially when dealing with file operations or unexpected user inputs.

## 🤝 Contributing

Contributions to **ArrayInsight Pro** are highly encouraged! If you have ideas for adding more statistical analyses, implementing different array operations (e.g., sorting, searching specific values), enhancing file formats, or improving cross-platform features:

1.  Fork the repository.
2.  Create a new branch for your feature (`git checkout -b feature/YourArrayEnhancement`).
3.  Make your changes and commit them (`git commit -m 'Feature: Implement YourArrayEnhancement'`).
4.  Push to the branch (`git push origin feature/YourArrayEnhancement`).
5.  Open a Pull Request.

Please ensure your code is well-commented, adheres to good C++ practices, and maintains a modular structure.

## 📃 License

This project is licensed under the **MIT License**.
(If you have a `LICENSE` file in your repository, refer to it: `See the LICENSE file for details.`)

## 📧 Contact

Created by **Adrian Lesniak**.
For questions, feedback, or issues, please open an issue on the GitHub repository or contact the repository owner.

---
🔬 _Analyzing arrays, discovering patterns, one element at a time._
