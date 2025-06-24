#include <iostream>
#include <string>
#include "../../include/pages/userDashboard.h"

void userDashboard(const std::string& username) {
    std::cout << "=== Welcome to the User Dashboard, " << username << "! ===" << std::endl;
    std::cout << "Please choose an option:" << std::endl;
    std::cout << "1. View projections" << std::endl;
    std::cout << "2. Buy a ticket" << std::endl;
    std::cout << "3. Exit";
}
