#include <iostream>
#include "../../include/pages/mainMenu.h"

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
        //to add login func
        break;
    case 2:
        std::cout << "Register selected!" << std::endl;
        //to add reg func
        break;
    case 3:
        std::cout << "Exiting application." << std::endl;
        break;
    default:
        std::cout << "Invalid choice." << std::endl;
        displayMainMenu();
    }
}