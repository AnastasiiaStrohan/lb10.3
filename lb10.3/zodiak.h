#pragma once
#ifndef ZODIAC_H
#define ZODIAC_H

#include <iostream>
#include <iomanip>
#include <string>

struct Zodiac {
    char lastName[30];
    char firstName[30];
    char zodiacSign[20];
    int birthDate[3]; // birthDate[0] - день, birthDate[1] - місяць, birthDate[2] - рік
};

// Прототипи функцій
void inputZodiacData(Zodiac*& zodiacs, int& n);
void sortZodiacsByLastName(Zodiac* zodiacs, int n);
void displayZodiacs(const Zodiac* zodiacs, int n);
void searchByZodiacSign(const Zodiac* zodiacs, int n, const char* sign);
void saveToFile(const Zodiac* zodiacs, int n, const char* filename);
void loadFromFile(Zodiac*& zodiacs, int& n, const char* filename);

#endif // ZODIAC_H

