/* Citation and Sources...
Final Project Milestone 2
Module: AidMan
Filename: AidMan.cpp
Version 1.0
Author	Ashwin B N
Revision History
-----------------------------------------------------------
Date      Reason
2023/11/13  Preliminary release
2023/11/13  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "AidMan.h"
#include "Utils.h"
#include "Date.h"

namespace sdds {

	AidMan::AidMan(const char* fileName) : m_filename(nullptr), m_mainMenu("List Items\tAdd Item\tRemove Item\tUpdate Quantity\tSort\tShip Items\tNew/Open Aid Database") {
		if (fileName && strlen(fileName) > 0) {
			ut.alocpy(m_filename, fileName);
		}
	}

	AidMan::~AidMan() {
		delete[] m_filename;
		m_filename = nullptr;
	}


	void AidMan::run() const {
		while (true){
			unsigned int choice = menu();
            switch (choice) {
            case 0:
                std::cout << "Exiting Program!" << std::endl;
                return;
            case 1:
                std::cout << "\n****List Items****\n\n";
                break;
            case 2:
                std::cout << "\n****Add Item****\n\n";
                break;
            case 3:
                std::cout << "\n****Remove Item****\n\n";
                break;
            case 4:
                std::cout << "\n****Update Quantity****\n\n";
                break;
            case 5:
                std::cout << "\n****Sort****\n\n";
                break;
            case 6:
                std::cout << "\n****Ship Items****\n\n";
                break;
            case 7:
                std::cout << "\n****New/Open Aid Database****\n\n";
                break;
            default:
                std::cout << "Invalid option!" << std::endl;
            }
		}
	}

	unsigned int AidMan::menu() const {
		Date date(0,0,0);
		std::cout << "Aid Management System" << std::endl;
		std::cout << "Date: ";
		date.write(std::cout) << std::endl;
		std::cout << "Data file: " << (m_filename ? m_filename : "No file") << std::endl << std::endl;

		return m_mainMenu.run();
	}

}
