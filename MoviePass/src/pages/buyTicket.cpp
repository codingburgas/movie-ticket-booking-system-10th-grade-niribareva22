#include "../../include/pages/buyTicket.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>

void BuyTicket::buyTicket() {
    system("cls");

    std::ifstream inFile("movies.txt");
    if (!inFile.is_open()) {
        std::cout << "Error: Cannot open movies.txt" << std::endl;
        return;
    }

    std::string movies[100];
    int movieCount = 0;

    while (std::getline(inFile, movies[movieCount])) {
        movieCount++;
    }
    inFile.close();

    if (movieCount == 0) {
        std::cout << "No movies found." << std::endl;
        return;
    }

    std::cout << "=== Available Movies ===" << std::endl;
    for (int i = 0; i < movieCount; i++) {
        std::string title = movies[i].substr(0, movies[i].find(','));
        std::cout << i + 1 << ". " << title << std::endl;
    }

    int choice;
    std::cout << "Choose a movie by number: ";
    std::cin >> choice;
    std::cin.ignore();

    if (choice < 1 || choice > movieCount) {
        std::cout << "Invalid choice." << std::endl;
        return;
    }

    std::string selectedMovie = movies[choice - 1];

    size_t pos = selectedMovie.rfind(',');
    std::string bookedSeats = "";
    std::string movieInfo = "";

    if (pos != std::string::npos && pos + 1 < selectedMovie.length()) {
        bookedSeats = selectedMovie.substr(pos + 1);
        movieInfo = selectedMovie.substr(0, pos);
    }
    else {
        movieInfo = selectedMovie;
    }

    char seats[4][8];
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 8; c++) {
            seats[r][c] = '_';
        }
    }

    std::string seatCode = "";
    for (size_t i = 0; i < bookedSeats.length(); i++) {
        char seatChar = bookedSeats[i];
        if (seatChar == ';' || i == bookedSeats.length() - 1) {
            if (i == bookedSeats.length() - 1 && seatChar != ';') {
                seatCode += seatChar;
            }
            if (seatCode.length() >= 2) {
                int row = seatCode[0] - 'A';
                int col = std::stoi(seatCode.substr(1)) - 1;
                if (row >= 0 && row < 4 && col >= 0 && col < 8) {
                    seats[row][col] = 'X';
                }
            }
            seatCode = "";
        }
        else {
            seatCode += seatChar;
        }
    }

    std::cout << "Seat Map ( _ = free, X = booked):" << std::endl;
    for (int r = 0; r < 4; r++) {
        std::cout << char('A' + r) << " ";
        for (int c = 0; c < 8; c++) {
            std::cout << seats[r][c] << " ";
        }
        std::cout << std::endl;
    }

    char rowChar;
    int seatNum;
    std::cout << "Choose row (A-D): ";
    std::cin >> rowChar;
    std::cout << "Choose seat number (1-8): ";
    std::cin >> seatNum;

    rowChar = toupper(rowChar);
    int row = rowChar - 'A';
    int col = seatNum - 1;

    if (row < 0 || row >= 4 || col < 0 || col >= 8) {
        std::cout << "Invalid seat." << std::endl;
        return;
    }

    if (seats[row][col] == 'X') {
        std::cout << "Seat already booked!" << std::endl;
        return;
    }

    std::string newSeat = std::string(1, rowChar) + std::to_string(seatNum);

    if (!bookedSeats.empty()) {
        bookedSeats += ";";
    }
    bookedSeats += newSeat;

    movies[choice - 1] = movieInfo + "," + bookedSeats;

    std::ofstream outFile("movies.txt");
    for (int i = 0; i < movieCount; i++) {
        outFile << movies[i] << std::endl;
    }
    outFile.close();

    std::cout << "Successfully booked seat " << newSeat << "!" << std::endl;

    int paymentChoice;
    std::cout << "Choose payment method:" << std::endl;
    std::cout << "1. Cash" << std::endl;
    std::cout << "2. Card" << std::endl;
    std::cout << "Enter choice: ";
    std::cin >> paymentChoice;
    std::cin.ignore();

    if (paymentChoice == 1) {
        std::cout << "You chose to pay with cash." << std::endl;
        std::cout << "Please pay in person at the cinema counter." << std::endl;
    }
    else if (paymentChoice == 2) {
        std::string name, cardNumber;
        std::cout << "You chose to pay with card." << std::endl;
        std::cout << "Enter your name: ";
        std::getline(std::cin, name);
        bool validCard = false;
        while (!validCard) {
            std::cout << "Enter card number (8 to 19 characters): ";
            std::getline(std::cin, cardNumber);

            if (cardNumber.length() >= 8 && cardNumber.length() <= 19) {
                validCard = true;
            }
            else {
                std::cout << "Card number must be between 8 and 19 characters." << std::endl;
            }
        }
        std::cout << "Payment processed. Thank you, " << name << "!" << std::endl;
    }
    else {
        std::cout << "Invalid payment option. Payment not recorded." << std::endl;
    }
}

