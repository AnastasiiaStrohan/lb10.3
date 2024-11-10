#include <iostream>
#include "zodiak.h"


int main() {
    Zodiac* zodiacs = nullptr;
    int n = 0;
    int choice;

    do {
        std::cout << "\n--- Menu ---\n";
        std::cout << "1. Input data\n";
        std::cout << "2. Display data\n";
        std::cout << "3. Sort by last name\n";
        std::cout << "4. Search by zodiac sign\n";
        std::cout << "5. Save to file\n";
        std::cout << "6. Load from file\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";

        while (!(std::cin >> choice) || choice < 0 || choice > 6) {
            std::cout << "Invalid input. Please enter a number between 0 and 6: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (choice) {
        case 1:
            inputZodiacData(zodiacs, n);
            break;
        case 2:
            displayZodiacs(zodiacs, n);
            break;
        case 3:
            sortZodiacsByLastName(zodiacs, n);
            std::cout << "Data sorted by last name.\n";
            break;
        case 4: {
            char sign[20];
            std::cout << "Enter zodiac sign to search: ";
            std::cin >> sign;
            searchByZodiacSign(zodiacs, n, sign);
            break;
        }
        case 5: {
            char filename[100];
            std::cout << "Enter filename to save data: ";
            std::cin >> filename;
            saveToFile(zodiacs, n, filename);
            break;
        }
        case 6: {
            char filename[100];
            std::cout << "Enter filename to load data: ";
            std::cin >> filename;
            loadFromFile(zodiacs, n, filename);
            break;
        }
        case 0:
            std::cout << "Exiting program...\n";
            break;
        }
    } while (choice != 0);

    delete[] zodiacs;
    return 0;
}
