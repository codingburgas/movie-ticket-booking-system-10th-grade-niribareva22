#include <iostream>
#include <fstream>
#include <functional>
#include "../../include/auth/registerAdmin.h"
#include "../../include/pages/adminDashboard.h"

void registerAdmin() {
    system("cls");
    std::string username, password;
    std::ofstream adminAccFile("adminAccounts.txt", std::ios_base::out | std::ios_base::app);

    std::cout << "--- Admin Registration ---" << std::endl;
    std::cout << "Enter admin username: ";
    std::cin >> username;
    adminAccFile <<"@"<< username << std::endl;
    std::cout << "Enter admin password: ";
    std::cin >> password;

    std::hash<std::string> hasher;
    size_t hashedPassword = hasher(password);

    adminAccFile << hashedPassword <<std::endl;
    adminDashboard(username);
}
