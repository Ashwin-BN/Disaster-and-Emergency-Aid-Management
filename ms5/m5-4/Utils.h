/***********************************************************************
// Final project Milestone 2
// Module: Utils
// File: Utils.h
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
#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

namespace sdds {
    const int sdds_testYear = 2023;
    const int sdds_testMon = 12;
    const int sdds_testDay = 9;
    class Utils {
        bool m_testMode = false;
    public:
        void getSystemDate(int* year = nullptr, int* mon = nullptr, int* day = nullptr);
        int daysOfMon(int mon, int year)const;
        void testMode(bool testmode = true);
        void alocpy(char*& destination, const char* source);
        int getint(const char* prompt = nullptr, const char* errMes = nullptr);
        int getint(int min, int max, const char* prompt = nullptr, const char* errMes = nullptr);
        double getDouble(const char* prompt = nullptr);
        double getDouble(double min, double max, const char* prompt = nullptr, const char* errMes = nullptr);
    };
    extern Utils ut;
}
#endif // !SDDS_UTILS_H
