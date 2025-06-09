#include <iostream>
#include "../../include/pages/mainMenu.h"
#include "../../include/auth/registerAdmin.h"
#include "../../include/auth/registerUser.h"


void displayMainMenu() {
    std::cout << "========== Main Menu ==========" << std::endl;
    std::cout << "1. Login" << std::endl;
    std::cout << "2. Register" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << "Please select an option: ";
    int choice;
    std::cin >> choice;

    switch (choice) {
    case 1:
        std::cout << "Login selected!" << std::endl;
        //log
        break;
    case 2:
        std::cout << "Register selected!" << std::endl;
        std::cout << "Select account type: 1. User or 2. Admin" << std::endl;
        int regChoice;
        std::cin >> regChoice;
        switch (regChoice) {
        case 1:
            std::cout << "User registration selected." << std::endl;
            registerUser();
            break;
        case 2:
            std::cout << "Admin registration selected." << std::endl;
            registerAdmin();
            break;
        }
    case 3:
        std::cout << "Exiting application." << std::endl;
        break;
    default:
        std::cout << "Invalid choice." << std::endl;
        break;
    }
}