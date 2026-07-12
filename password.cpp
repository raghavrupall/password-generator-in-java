#include <iostream>
#include <string>
#include <random>

std::string generatePassword(int length, bool useUpper, bool useDigits, bool useSymbols) {
    std::string chars = "abcdefghijklmnopqrstuvwxyz";
    if (useUpper)   chars += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (useDigits)  chars += "0123456789";
    if (useSymbols) chars += "!@#$%^&*()-_=+[]{}";

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, chars.size() - 1);

    std::string password;
    for (int i = 0; i < length; ++i)
        password += chars[dist(gen)];

    return password;
}

int main() {
    int length;
    char upperChoice, digitChoice, symbolChoice;

    std::cout << "Password length: ";
    std::cin >> length;

    std::cout << "Include uppercase letters? (y/n): ";
    std::cin >> upperChoice;
    std::cout << "Include digits? (y/n): ";
    std::cin >> digitChoice;
    std::cout << "Include symbols? (y/n): ";
    std::cin >> symbolChoice;

    std::string password = generatePassword(
        length,
        upperChoice == 'y' || upperChoice == 'Y',
        digitChoice == 'y' || digitChoice == 'Y',
        symbolChoice == 'y' || symbolChoice == 'Y'
    );

    std::cout << "Generated password: " << password << std::endl;
    return 0;
}