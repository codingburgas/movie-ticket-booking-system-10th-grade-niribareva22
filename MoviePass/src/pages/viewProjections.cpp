#include "../../include/pages/viewProjections.h"
#include <iostream>
#include <fstream>
#include <string>

void ViewProjections::showProjections() {
    system("cls");
    std::cout << "=== Current Movie Projections ===" << std::endl;

    std::ifstream file("movies.txt");

    if (file.is_open()) {
        std::string line;
        bool found = false;

        while (std::getline(file, line)) {
            size_t titleEnd = line.find(',');
            size_t genreEnd = line.find(',', titleEnd + 1);

            if (titleEnd != std::string::npos && genreEnd != std::string::npos) {
                std::string title = line.substr(0, titleEnd);
                std::string genre = line.substr(titleEnd + 1, genreEnd - titleEnd - 1);
                std::string year = line.substr(genreEnd + 1);

                std::cout << "Title: " << title
                    << " | Genre: " << genre
                    << " | Year: " << year << std::endl;
                found = true;
            }
        }

        file.close();

        if (!found) {
            std::cout << "No movie projections found." << std::endl;
        }
    }
    else {
        std::cout << "Error: Could not open movies.txt." << std::endl;
    }

  
}
