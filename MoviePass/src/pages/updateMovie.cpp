#include "../../include/pages/updateMovie.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void UpdateMovie::updateMovie() {
    system("cls");

    std::string titleToUpdate;
    std::cout << "=== Update Movie ===" << std::endl;
    std::cin.ignore();
    std::cout << "Enter the exact movie title to update: ";
    std::getline(std::cin, titleToUpdate);

    std::ifstream inFile("movies.txt");
    std::vector<std::string> movies;
    std::string line;
    bool found = false;

    if (inFile.is_open()) {
        while (std::getline(inFile, line)) {
            size_t firstComma = line.find(',');
            std::string currentTitle = line.substr(0, firstComma);

            if (currentTitle == titleToUpdate) {
                found = true;

                std::string newTitle, newGenre;
                int newYear;

                std::cout << "Enter new title: ";
                std::getline(std::cin, newTitle);
                std::cout << "Enter new genre: ";
                std::getline(std::cin, newGenre);
                std::cout << "Enter new release year: ";
                std::cin >> newYear;

                std::string updatedMovie = newTitle + "," + newGenre + "," + std::to_string(newYear);
                movies.push_back(updatedMovie);
            }
            else {
                movies.push_back(line);
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
            std::cout << "Movie updated successfully." << std::endl;
        }
        else {
            std::cout << "Movie title not found." << std::endl;
        }
    }
    else {
        std::cout << "Error: Could not write to file." << std::endl;
    }
}
