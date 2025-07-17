#ifndef PASSCRAFT_H
#define PASSCRAFT_H

#include <vector>
#include <string>
#include <random>
#include <thread>
#include <chrono>

class PassCraft {
private:
    void mainMenu();
    void passwordOptions();
    void passphraseOptions();
    void generatePassword(int length, bool useLower, bool useUpper, bool useNumbers, bool useSymbols);
    void generatePassphrase(int wordCount);
    
    void clearScreen();
    void showBanner();
    int getIntInput(const std::string& prompt, int min);
    bool getBoolInput(const std::string& prompt);
    
    const std::vector<std::string> wordList;
    std::random_device rd;
    std::mt19937 gen;

public:
    PassCraft();
    void run();
};

#endif // PASSCRAFT_H