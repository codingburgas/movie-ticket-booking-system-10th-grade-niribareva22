#include "../../include/pages/addMovie.h"
#include <iostream>
#include <fstream>
#include <string>

void AddMovie::addMovie() {
    std::string movieTitle;
    std::string movieGenre;
    int releaseYear;

    std::cout << "=== Add Movie ===" << std::endl;

    std::cin.ignore();

    std::cout << "Enter movie title: " << std::endl;
    std::getline(std::cin, movieTitle);

    std::cout << "Enter movie genre: " << std::endl;
    std::getline(std::cin, movieGenre);

    std::cout << "Enter release year: " << std::endl;
    std::cin >> releaseYear;

    std::ofstream file("movies.txt", std::ios::app);
    if (file.is_open()) {
        file << movieTitle << "," << movieGenre << "," << releaseYear << std::endl;

        file.close();
        std::cout << "Movie added successfully!" << std::endl;
    }
    else {
        std::cout << "Error: Could not open file to save movie." << std::endl;
    }
}
