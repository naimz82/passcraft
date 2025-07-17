#include "passcraft.h"
#include "wordlist.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <chrono>
#include <thread>
#include <limits>
#include <random>

//PassCraft::PassCraft() : gen(rd()) {}
PassCraft::PassCraft() : gen(std::chrono::steady_clock::now().time_since_epoch().count()) {
    // Constructor body can be empty or contain initialization code
}

void PassCraft::clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void PassCraft::showBanner() {
    clearScreen();
    std::cout << "================================\n";
    std::cout << "      PASSCRAFT GENERATOR       \n";
    std::cout << "================================\n\n";
}

int PassCraft::getIntInput(const std::string& prompt, int min) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value && value >= min) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a number equal to or larger than " << min << ".\n";
    }
}

bool PassCraft::getBoolInput(const std::string& prompt) {
    char answer;
    while (true) {
        std::cout << prompt;
        std::cin >> answer;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        answer = tolower(answer);
        if (answer == 'y' || answer == 'n') {
            return answer == 'y';
        }
        std::cout << "Please enter 'y' or 'n'.\n";
    }
}

void PassCraft::mainMenu() {
    showBanner();
    std::cout << "Main Menu:\n";
    std::cout << "1. Generate Password\n";
    std::cout << "2. Generate Passphrase\n";
    std::cout << "3. Exit\n";
    
    int choice = getIntInput("Choose an option (1-3): ", 1);
    
    switch (choice) {
        case 1:
            passwordOptions();
            break;
        case 2:
            passphraseOptions();
            break;
        case 3:
            std::cout << "\nGoodbye!\n";
            exit(0);
        default:
            std::cout << "Invalid choice. Please try again.\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            mainMenu();
    }
}

void PassCraft::passwordOptions() {
    showBanner();
    std::cout << "PASSWORD OPTIONS\n\n";
    
    int length = getIntInput("Enter password length (min 8): ", 8);
    
    bool useLower = getBoolInput("Include lowercase letters? (y/n): ");
    bool useUpper = getBoolInput("Include uppercase letters? (y/n): ");
    bool useNumbers = getBoolInput("Include numbers? (y/n): ");
    bool useSymbols = getBoolInput("Include symbols? (y/n): ");
    
    if (!useLower && !useUpper && !useNumbers && !useSymbols) {
        std::cout << "You must select at least one character type.\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        passwordOptions();
        return;
    }
    
    generatePassword(length, useLower, useUpper, useNumbers, useSymbols);
}

void PassCraft::generatePassword(int length, bool useLower, bool useUpper, 
                               bool useNumbers, bool useSymbols) {
    std::string charPool;
    const std::string lowercase = "abcdefghijklmnopqrstuvwxyz";
    const std::string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string numbers = "0123456789";
    const std::string symbols = "!@#$%^&*()_+-=[]{}|;:,.<>?";
    
    if (useLower) charPool += lowercase;
    if (useUpper) charPool += uppercase;
    if (useNumbers) charPool += numbers;
    if (useSymbols) charPool += symbols;
    
    std::uniform_int_distribution<> dist(0, charPool.size() - 1);
    std::string password;
    
    for (int i = 0; i < length; ++i) {
        password += charPool[dist(gen)];
    }
    
    showBanner();
    std::cout << "=== GENERATED PASSWORD ===\n";
    std::cout << password << "\n";
    std::cout << "==========================\n\n";
    
    std::cout << "Press Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    mainMenu();
}

void PassCraft::passphraseOptions() {
    showBanner();
    std::cout << "PASSPHRASE OPTIONS\n\n";
    
    int count = getIntInput("Enter number of words (min 4): ", 4);
    generatePassphrase(count);
}

void PassCraft::generatePassphrase(int wordCount) {
    const auto& wordList = getWordList();
    std::uniform_int_distribution<size_t> dist(0, wordList.size() - 1);
    std::string passphrase;
    
    for (int i = 0; i < wordCount; ++i) {
        passphrase += wordList[dist(gen)];
        if (i < wordCount - 1) passphrase += " ";
    }
    
    showBanner();
    std::cout << "=== GENERATED PASSPHRASE ===\n";
    std::cout << passphrase << "\n";
    std::cout << "===========================\n\n";
    
    std::cout << "Press Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    mainMenu();
}

void PassCraft::run() {
    showBanner();
    std::cout << "Welcome to PassCraft!\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    mainMenu();
}

int main() {
    // Debug: Verify word list loaded
    const auto& wordList = getWordList();
    std::cout << "Word list size: " << wordList.size() << std::endl;
    if (wordList.empty()) {
        std::cerr << "ERROR: Word list is empty!" << std::endl;
        return 1;
    }

    PassCraft app;
    app.run();
    return 0;
}