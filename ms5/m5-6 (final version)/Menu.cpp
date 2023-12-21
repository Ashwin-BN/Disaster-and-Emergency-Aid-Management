/* Citation and Sources...
Final Project Milestone 5 part 6
Module: Menu
Filename: Menu.cpp
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
#include<cstring>
#include <iostream>
#include <sstream>

#include "Menu.h"
#include "Utils.h"


namespace sdds {

	Menu::Menu(const char* content) : m_menuContent(nullptr) {
		if (content && strlen(content) > 0) {
			if (numOfItems(content) <= maxContent) {
				ut.alocpy(m_menuContent, content);
			}
		}
	}

	int Menu::numOfItems(const char* content) const {
		
		int count = 1;
		if (!content && strlen(content) == 0) {
			count = 0;
		}
		else{
			for (size_t i = 0; i < strlen(content); i++) {
				if (content[i] == '\t') {
					count++;
				}
			}
		}
		return count;
	}

	Menu::~Menu() {
		delete[] m_menuContent;
		m_menuContent = nullptr;
	}

	unsigned int Menu::run() const {
		unsigned int choice;
		
		if (!m_menuContent) {
			std::cout << "Invalid Menu!" << std::endl;
			return 0;
		}

		display(std::cout);
		std::cout << "---------------------------------" << std::endl;
		std::cout << "0- Exit" << std::endl;

		choice = ut.getint(0, numOfItems(m_menuContent), "> ", "Invalid Integer");

		return choice;

	}

	void Menu::display(std::ostream& os) const {
		int itemNo = 1;
		std::istringstream stream(m_menuContent);
		std::string token;

		while (getline(stream, token, '\t') && itemNo<=numOfItems(m_menuContent)) {
			os << itemNo << "- " << token << std::endl;
			itemNo++;
		}
	}
}