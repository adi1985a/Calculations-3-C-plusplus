# Array Analysis Program

## Overview
This C++ console application analyzes arrays with a menu-driven interface. It generates three arrays (X, Y, Z) of 12 elements with random numbers in a user-defined range, displays them, calculates the mean and counts elements above the mean for array X, and saves/loads results. It features colored output, logging via `logger.h`, and file handling via `file_handler.h`.

## Features
- **Array Operations**:
  - `ArrayUtils::fillArray`: Fills arrays with random numbers in range [p, k].
  - `ArrayUtils::printArray`: Displays arrays in a formatted layout.
  - `ArrayUtils::calculateMean`: Computes arithmetic mean of array X.
  - `ArrayUtils::countElementsAboveMean`: Counts elements above the mean in X.
- **File I/O**:
  - `FileHandler::saveResults`: Saves mean and count to `results.txt`.
  - `FileHandler::loadArrayFromFile`: Loads array from `saved_array.txt`.
- **Interface**:
  - `displayHeader`: Shows program title and description with ASCII art.
  - `displayMenu`: Lists options: generate arrays, display arrays, calculate statistics, save/load results, exit.
  - Colored output using ANSI codes (red, green, yellow, cyan, white).
- **Utilities**:
  - `clearScreen`: Clears console (`cls` for Windows, `clear` for others).
  - `waitForEnter`: Pauses for user input to return to menu.
  - `Logger`: Logs program events and errors (via `logger.h`).
- **Main Program**:
  - Loops until user selects exit (0).
  - Validates input and handles exceptions.

## Requirements
- C++ compiler (e.g., g++, clang++) with C++11 or later
- Standard C++ libraries: `<iostream>`, `<iomanip>`, `<stdexcept>`, `<limits>`
- Custom headers: `array_utils.h`, `logger.h`, `file_handler.h` (assumed to provide array utilities, logging, and file handling)
- Operating system: Any supporting a C++ compiler (e.g., Windows, Linux, macOS)
- Write permissions for `results.txt` and `saved_array.txt`
- Terminal supporting ANSI color codes for colored output

## Setup
1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd <repository-directory>
   ```
2. Ensure `array_utils.h`, `logger.h`, and `file_handler.h` are in the project directory with required functions (e.g., `ArrayUtils::fillArray`, `Logger::log`, `FileHandler::saveResults`).
3. Save the provided code as `array_analysis.cpp`.
4. Compile the program:
   ```bash
   g++ array_analysis.cpp -o array_analysis
   ```
5. Run the program:
   ```bash
   ./array_analysis
   ```

## Usage
1. Compile and run the program using the steps above.
2. **Interface**:
   - Displays a header and menu with options:
     1. Generate new arrays
     2. Display arrays
     3. Calculate statistics
     4. Save results
     5. Load previous results
     0. Exit
3. **Input**:
   - Enter 0–5 to select an option.
   - For option 1, input range bounds `p` and `k`.
   - Invalid inputs trigger error messages and retries.
4. **Output**:
   - Option 1: Confirms array generation.
   - Option 2: Shows arrays X, Y, Z (e.g., "Array X: 3 5 7 ...").
   - Option 3: Displays mean and count above mean for X (e.g., "Mean: 6.5, Elements above mean: 4").
   - Option 4: Confirms saving to `results.txt`.
   - Option 5: Shows loaded array from `saved_array.txt`.
   - Errors logged via `Logger::error` to a log file.
5. **Actions**:
   - Press Enter to return to menu after each operation.
   - Select 0 to exit.

## File Structure
- `array_analysis.cpp`: Main C++ source file with program logic.
- `array_utils.h`: Header for array utility functions (assumed, not provided).
- `logger.h`: Header for logging functions (assumed, not provided).
- `file_handler.h`: Header for file handling functions (assumed, not provided).
- `results.txt`: Output file for statistical results (created/appended).
- `saved_array.txt`: File for stored array data (read by option 5).
- `README.md`: This file, providing project documentation.

## Notes
- Requires `array_utils.h`, `logger.h`, and `file_handler.h` with functions like `fillArray`, `log`, and `saveResults`.
- Cross-platform screen clearing with `#ifdef _WIN32` for Windows compatibility.
- ANSI color codes enhance output; ensure terminal support (e.g., Windows Terminal, Linux terminals).
- Input validation prevents non-numeric inputs; logs errors for debugging.
- Extend by adding more statistics, sorting arrays, or GUI support.
- Ensure write permissions for `results.txt` and `saved_array.txt`.
- No external dependencies beyond standard C++ libraries and custom headers.

## Contributing
Contributions are welcome! To contribute:
1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Make changes and commit (`git commit -m "Add feature"`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a pull request.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contact
For questions or feedback, open an issue on GitHub or contact the repository owner.