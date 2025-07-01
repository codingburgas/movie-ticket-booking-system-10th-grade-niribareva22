#include <iostream>
#include <string>
#include "../../include/pages/userDashboard.h"
#include "../../include/pages/mainMenu.h"
#include "../../include/pages/viewProjections.h"
#include "../../include/pages/buyTicket.h"

void userDashboard(const std::string& username) {
    system("cls");
    std::cout << "=== Welcome to the User Dashboard, " << username << "! ===" << std::endl;
    std::cout << "Please choose an option:" << std::endl;
    std::cout << "1. View projections" << std::endl;
    std::cout << "2. Buy a ticket" << std::endl;
    std::cout << "3. Exit" << std::endl;

    int choice;
    std::cin >> choice;

    ViewProjections viewer;
    BuyTicket buyer;

    switch (choice) {
    case 1:
        std::cout << "You chose to view projections." << std::endl;
        viewer.showProjections();
        std::cout << "Press Enter to return to the dashboard..." << std::endl;
        std::cin.ignore();
        std::cin.get();
        userDashboard(username);
        break;
    case 2:
        std::cout << "You chose to buy a ticket." << std::endl;
        buyer.buyTicket();
        std::cout << "Press Enter to return to the dashboard..." << std::endl;
        std::cin.ignore();
        std::cin.get();
        userDashboard(username);
        break;
    case 3:
        std::cout << "Exiting the dashboard." << std::endl;
        displayMainMenu();
        break;
    }

}
