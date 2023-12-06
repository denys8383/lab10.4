#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

int findMaxDigitSequence(const std::string& str) {
    int currentSequence = 0;
    int maxSequence = 0;

    for (char ch : str) {
        if (std::isdigit(ch)) {
            ++currentSequence;
        }
        else {
            maxSequence = std::max(currentSequence, maxSequence);
            currentSequence = 0;
        }
    }

    return std::max(currentSequence, maxSequence);
}

int writeToOutputFile(const std::string& outputFileName) {
    std::ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        return -1; // Error opening output file
    }

    std::cout << "Enter lines (type 'exit' to finish input):" << std::endl;
    std::string line;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, line);

        if (line == "exit") {
            break;
        }

        int maxDigitSequence = findMaxDigitSequence(line);
        outputFile << "Max digit sequence length: " << maxDigitSequence << std::endl;
    }

    outputFile.close();
    return 0; // Success
}

int readAndPrintFileContents(const std::string& filename) {
    std::ifstream resultFile(filename);
    if (resultFile.is_open()) {
        std::string resultLine;
        while (std::getline(resultFile, resultLine)) {
            std::cout << resultLine << std::endl;
        }
        resultFile.close();
        return 0; // Success
    }
    else {
        return -1; // Error opening file for reading
    }
}

void displayUserMenu() {
    while (true) {
        int choice;
        std::cout << "Menu:\n"
            << "1. Enter lines and write to file\n"
            << "2. Read and print file contents\n"
            << "3. Exit\n";

        std::cout << "Enter your choice (1, 2, or 3): ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::cout << "Enter the output file name: ";
            std::string outputFileName;
            std::cin.ignore();
            std::getline(std::cin, outputFileName);
            int result = writeToOutputFile(outputFileName);
            if (result == 0) {
                std::cout << "Results written to " << outputFileName << std::endl;
            }
            else {
                std::cerr << "Error opening output file." << std::endl;
            }
            break;
        }
        case 2: {
            std::cout << "Enter the output file name to read: ";
            std::string outputFileName;
            std::cin.ignore();
            std::getline(std::cin, outputFileName);
            int result = readAndPrintFileContents(outputFileName);
            if (result != 0) {
                std::cerr << "Error opening file for reading." << std::endl;
            }
            break;
        }
        case 3:
            std::cout << "Exiting program." << std::endl;
            return;
        default:
            std::cerr << "Invalid choice. Please try again." << std::endl;
            break;
        }
    }
}

int main() {
    displayUserMenu();
    return 0;
}
