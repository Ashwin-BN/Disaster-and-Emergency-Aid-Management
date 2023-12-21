/***********************************************************************
// Final project Milestone 2
// Module: Utils
// File: Utils.cpp
// Version 1.0
// Author  Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name: Ashwin B N
// Section: NGG
// Student Id: 112763222
// Email: abharathan-nettoor@myseneca.ca
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <ctime>
#include <iomanip>
#include "Utils.h"
using namespace std;
namespace sdds {
    Utils ut;
    void Utils::testMode(bool testmode) {
        m_testMode = testmode;
    }
    void Utils::getSystemDate(int* year, int* mon, int* day) {
        if (m_testMode) {
            if (day) *day = sdds_testDay;
            if (mon) *mon = sdds_testMon;
            if (year) *year = sdds_testYear;
        }
        else {
            time_t t = std::time(NULL);
            tm lt = *localtime(&t);
            if (day) *day = lt.tm_mday;
            if (mon) *mon = lt.tm_mon + 1;
            if (year) *year = lt.tm_year + 1900;
        }
    }
    int Utils::daysOfMon(int month, int year)const {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = (month >= 1 && month <= 12 ? month : 13) - 1;
        return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }

    void Utils::alocpy(char*& destination, const char* source) {
        delete[] destination;
        destination = nullptr;
        if (source) {
            destination = new char[strlen(source) + 1];
            strcpy(destination, source);
        }
    }

    int Utils::getint(const char* prompt) {
        int input;
        bool flag = false;
        do {
            if (prompt) {
                cout << prompt;
            }

            if (!(cin >> input)) {
                cin.clear();
                cin.ignore(1000, '\n');
                return -1;
            }
            else {
                flag = true;
            }
        } while (!flag);

        return input;
    }

    int Utils::getint(int min, int max, const char* prompt, const char* errMes) {
        int input = getint(prompt);
        while (input < min || input > max) {
            if (errMes != nullptr && input == (-1)) {
                std::cout << errMes << ", retry: ";
                input = getint(nullptr);
            }
            else {
                std::cout << "Value out of range [" << min << "<=val<=" << max << "]: ";
                input = getint(nullptr);
            }
        }
        return input;
    }

    double Utils::getDouble(const char* prompt) {
        double input;
        bool flag = false;
        do {
            if (prompt) {
                cout << prompt;
            }

            if (!(cin >> input)) {
                cin.clear();
                cin.ignore(1000, '\n');
                return -1;
            }
            else {
                flag = true;
            }
        } while (!flag);

        return input;
    }

    double Utils::getDouble(double min, double max, const char* prompt, const char* errMes) {
        double input = getDouble(prompt);
        while (input < min || input > max) {
            if (errMes != nullptr && input == (-1.0)) {
                std::cout << errMes << ", retry: ";
                input = getDouble(nullptr);
            }
            else {
                std::cout << "Value out of range [" << std::fixed << std::setprecision(2)
                    << std::setfill('0')  << min << "<=val<=" << std::setfill('0') << max << "]: ";
                input = getDouble(nullptr);
            }
        }
        return input;
    }
}