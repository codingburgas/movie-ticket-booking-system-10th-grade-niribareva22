#include <iostream>
#include <fstream>
#include <functional>
#include "../../include/auth/registerUser.h"
#include "../../include/pages/userDashboard.h"

void registerUser() {
    system("cls");
    std::string username, password;
    std::ofstream userAccFile("userAccounts.txt", std::ios_base::out | std::ios_base::app);

    std::cout << "--- User Registration ---" << std::endl;
    std::cout << "Enter user's username: ";
    std::cin >> username;
    userAccFile << "@" << username << std::endl;
    std::cout << "Enter user's password: ";
    std::cin >> password;

    std::hash<std::string> hasher;
    size_t hashedPassword = hasher(password);

    userAccFile << hashedPassword << std::endl;
    userDashboard(username);
}
