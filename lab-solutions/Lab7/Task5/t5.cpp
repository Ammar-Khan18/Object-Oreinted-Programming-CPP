#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>

void checkPassword(const std::string& password) {
    // Check if password is at least 8 characters long
    if (password.length() < 8) {
        throw std::runtime_error("Password must be at least 8 characters long.");
    }
    
    // Check if password contains at least one digit
    bool hasDigit = false;
    for (char c : password) {
        if (std::isdigit(c)) {
            hasDigit = true;
            break;
        }
    }
    
    if (!hasDigit) {
        throw std::runtime_error("Password must contain at least one digit.");
    }
    
    // If we've reached here, the password meets all requirements
    std::cout << "Password is strong and valid." << std::endl;
}

int main() {
    std::string password;
    
    std::cout << "Enter a password: ";
    std::cin >> password;
    
    try {
        checkPassword(password);
    } catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
        std::cout << "Please try a different password." << std::endl;
    }
    
    return 0;
}