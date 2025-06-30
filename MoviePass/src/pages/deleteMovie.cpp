#include "../../include/pages/deleteMovie.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void DeleteMovie::deleteMovie() {
    system("cls");

    std::string movieTitleToDelete;
    std::cout << "=== Delete Movie ===" << std::endl;
    std::cin.ignore();
    std::cout << "Enter the movie title to delete: ";
    std::getline(std::cin, movieTitleToDelete);

    std::ifstream inFile("movies.txt");
    std::vector<std::string> movies;
    std::string line;
    bool found = false;

    if (inFile.is_open()) {
        while (std::getline(inFile, line)) {
            
            size_t firstComma = line.find(',');

            std::string currentTitle = line.substr(0, firstComma);

            if (currentTitle != movieTitleToDelete) {
                movies.push_back(line); 
            }
            else {
                found = true; 
            }
        }
        inFile.close();
    }
    else {
        std::cout << "Error: Could not open file." << std::endl;
        return;
    }

    std::ofstream outFile("movies.txt");
    if (outFile.is_open()) {
        for (const std::string& movie : movies) {
            outFile << movie << std::endl;
        }
        outFile.close();

        if (found) {
            std::cout << "Movie titled \"" << movieTitleToDelete << "\" deleted successfully." << std::endl;
        }
        else {
            std::cout << "Movie title not found." << std::endl;
        }
    }
    else {
        std::cout << "Error: Could not write to file." << std::endl;
    }
}
