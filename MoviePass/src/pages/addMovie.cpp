#include "../../include/pages/addMovie.h"
#include <iostream>
#include <fstream>
#include <string>

void AddMovie::inputDetails(){
    system("cls");
    std::cin.ignore();
     std::cout << "=== Add Movie ===" << std::endl;

    std::cout << "Enter movie title: ";
    std::getline(std::cin, title);

    std::cout << "Enter movie genre: ";
    std::getline(std::cin, genre);

    std::cout << "Enter release year: ";
    std::cin >> releaseYear;
}

void AddMovie::saveToFile() {
    std::ofstream file("movies.txt", std::ios::app);
    if (file.is_open()) {
        file << title << "," << genre << "," << releaseYear << std::endl;
        file.close();
        std::cout << "Movie added successfully!" << std::endl;
    }
    else {
        std::cout << "Error: Could not open movies.txt" << std::endl;
    }
}