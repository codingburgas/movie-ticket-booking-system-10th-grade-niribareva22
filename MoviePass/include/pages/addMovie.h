#pragma once
#include <string>

class AddMovie{
private:
    std::string title;
    std::string genre;
    int releaseYear;
public:
    void inputDetails();
    void saveToFile();
};