#include <iostream>
#include <fstream>
#include <string>
#include "../../include/auth/login.h"

void loginUser() {
    int accountType;
    std::string inputUsername, inputPassword;
    std::string fileUsername, filePassword;
    std::string filePath;

    std::cout << "--- Login ---" << std::endl;
    std::cout << "1. User Login" << std::endl;
    std::cout << "2. Admin Login" << std::endl;
    std::cout << "Choose login type: ";
    std::cin >> accountType;

    if (accountType == 1) {
        filePath = "userAccounts.txt";
    }
    else if (accountType == 2) {
        filePath = "adminAccounts.txt";
    }

    std::cout << "Enter username: ";
    std::cin >> inputUsername;
    std::cout << "Enter password: ";
    std::cin >> inputPassword;

    std::ifstream accFile(filePath);
    bool loginSuccess = false;

    while (std::getline(accFile, fileUsername) && std::getline(accFile, filePassword)) {
        if (fileUsername[0] == '@') fileUsername = fileUsername.substr(1);

        if (fileUsername == inputUsername && filePassword == inputPassword) {
            loginSuccess = true;
            break;
        }
    }

    accFile.close();

    if (loginSuccess) {
        std::string role;
        if (accountType == 1) {
            role = "User";
        }
        else {
            role = "Admin";
        }

        std::cout << role << " login successful. Welcome, " << inputUsername << "!" << std::endl;
    }
    else {
        std::cout << "Login failed. Invalid username or password." << std::endl;
    }
}
