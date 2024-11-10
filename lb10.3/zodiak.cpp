#include "pch.h"
#include <limits>
#include <cstdio>
#include <cstring>
#include <iomanip> // Додано для std::setw
#include "zodiak.h"

// Функція для введення даних про людей з клавіатури
void inputZodiacData(Zodiac*& zodiacs, int& n) {
    std::cout << "Enter the number of people: ";
    while (!(std::cin >> n) || n <= 0) {
        std::cout << "Invalid input. Enter a positive integer: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    zodiacs = new Zodiac[n];

    for (int i = 0; i < n; ++i) {
        std::cout << "\nPerson #" << i + 1 << ":\n";
        std::cout << "Enter last name: ";
        std::cin >> zodiacs[i].lastName;
        std::cout << "Enter first name: ";
        std::cin >> zodiacs[i].firstName;
        std::cout << "Enter zodiac sign: ";
        std::cin >> zodiacs[i].zodiacSign;
        std::cout << "Enter birth day (day month year): ";
        while (!(std::cin >> zodiacs[i].birthDate[0] >> zodiacs[i].birthDate[1] >> zodiacs[i].birthDate[2]) ||
            zodiacs[i].birthDate[0] < 1 || zodiacs[i].birthDate[0] > 31 ||
            zodiacs[i].birthDate[1] < 1 || zodiacs[i].birthDate[1] > 12 ||
            zodiacs[i].birthDate[2] < 1900 || zodiacs[i].birthDate[2] > 2100) {
            std::cout << "Invalid date. Enter birth day (day month year): ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

// Функція для сортування масиву за прізвищами
void sortZodiacsByLastName(Zodiac* zodiacs, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (std::strcmp(zodiacs[j].lastName, zodiacs[j + 1].lastName) > 0) {
                std::swap(zodiacs[j], zodiacs[j + 1]);
            }
        }
    }
}

// Функція для виведення даних на екран
void displayZodiacs(const Zodiac* zodiacs, int n) {
    std::cout << "\nList of People:\n";
    std::cout << std::left << std::setw(15) << "Last Name" << std::setw(15) << "First Name"
        << std::setw(12) << "Zodiac Sign" << "Birth Date\n";
    std::cout << std::string(50, '-') << std::endl;

    for (int i = 0; i < n; ++i) {
        std::cout << std::left << std::setw(15) << zodiacs[i].lastName << std::setw(15) << zodiacs[i].firstName
            << std::setw(12) << zodiacs[i].zodiacSign << zodiacs[i].birthDate[0] << "/"
            << zodiacs[i].birthDate[1] << "/" << zodiacs[i].birthDate[2] << std::endl;
    }
}

// Функція для пошуку людей за знаком зодіаку
void searchByZodiacSign(const Zodiac* zodiacs, int n, const char* sign) {
    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (std::strcmp(zodiacs[i].zodiacSign, sign) == 0) {
            if (!found) {
                std::cout << "\nPeople born under the sign \"" << sign << "\":\n";
                std::cout << std::left << std::setw(15) << "Last Name" << std::setw(15) << "First Name"
                    << std::setw(12) << "Zodiac Sign" << "Birth Date\n";
                std::cout << std::string(50, '-') << std::endl;
            }
            std::cout << std::left << std::setw(15) << zodiacs[i].lastName << std::setw(15) << zodiacs[i].firstName
                << std::setw(12) << zodiacs[i].zodiacSign << zodiacs[i].birthDate[0] << "/"
                << zodiacs[i].birthDate[1] << "/" << zodiacs[i].birthDate[2] << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "No people found with the zodiac sign \"" << sign << "\".\n";
    }
}

// Функція для запису масиву у файл
void saveToFile(const Zodiac* zodiacs, int n, const char* filename) {
    FILE* outFile;
    if (fopen_s(&outFile, filename, "w") != 0) {
        std::cout << "Error opening file for writing.\n";
        return;
    }

    for (int i = 0; i < n; ++i) {
        fprintf(outFile, "%s %s %s %d %d %d\n",
            zodiacs[i].lastName,
            zodiacs[i].firstName,
            zodiacs[i].zodiacSign,
            zodiacs[i].birthDate[0],
            zodiacs[i].birthDate[1],
            zodiacs[i].birthDate[2]);
    }

    fclose(outFile);
    std::cout << "Data successfully saved to " << filename << std::endl;
}

// Функція для зчитування даних з файлу
void loadFromFile(Zodiac*& zodiacs, int& n, const char* filename) {
    FILE* inFile;
    if (fopen_s(&inFile, filename, "r") != 0) {
        std::cout << "Error opening file for reading.\n";
        return;
    }

    n = 0;
    Zodiac tempArray[100]{}; // Тимчасовий масив для зберігання даних з файлу

    while (fscanf_s(inFile, "%29s %29s %19s %d %d %d",
        tempArray[n].lastName, (unsigned)_countof(tempArray[n].lastName),
        tempArray[n].firstName, (unsigned)_countof(tempArray[n].firstName),
        tempArray[n].zodiacSign, (unsigned)_countof(tempArray[n].zodiacSign),
        &tempArray[n].birthDate[0],
        &tempArray[n].birthDate[1],
        &tempArray[n].birthDate[2]) == 6) {
        n++;
    }
    fclose(inFile);

    // Створюємо новий динамічний масив і копіюємо дані з тимчасового масиву
    delete[] zodiacs;
    zodiacs = new Zodiac[n];
    for (int i = 0; i < n; ++i) {
        zodiacs[i] = tempArray[i];
    }

    std::cout << "Data successfully loaded from " << filename << std::endl;
}
