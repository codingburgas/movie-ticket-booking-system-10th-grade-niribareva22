#include <iostream>
#include <string>
#include "../../include/pages/adminDashboard.h"
#include "../../include/pages/mainMenu.h"
#include "../../include/pages/addMovie.h"
#include "../../include/pages/deleteMovie.h"



void adminDashboard(const std::string& username) {
    system("cls");
    std::cout << "=== Welcome to the Admin Dashboard, " << username << "! ===" << std::endl;
    std::cout << "Please choose an option:" << std::endl;
    std::cout << "1. Add a movie" << std::endl;
    std::cout << "2. Delete a movie" << std::endl;
    std::cout << "3. Update a movie" << std::endl;
    std::cout << "4. Exit"<< std::endl;

    int choice;
    std::cin >> choice;
    AddMovie adder;
    DeleteMovie deleter;
    switch (choice) {
    case 1:
        std::cout << "You chose to add a movie." << std::endl;
        adder.addMovie();
        break;
    case 2:
        std::cout << "You chose to delete a movie." << std::endl;
        deleter.deleteMovie();
        break;
    case 3:
        std::cout << "You chose to update a movie." << std::endl;
      
        break;
    case 4:
        std::cout << "Exiting the dashboard." << std::endl;
        displayMainMenu();
        break;
    }
}
