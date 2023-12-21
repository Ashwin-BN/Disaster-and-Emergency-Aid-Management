/* Citation and Sources...
Final Project Milestone 5 part 6
Module: Menu
Filename: Menu.h
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

#ifndef SDDS_MENU_H
#define SDDS_MENU_H

#include <ostream>

namespace sdds {
	const int maxContent = 15;
	class Menu {
	private:
		char* m_menuContent;

		// To find number items in the menu
		int numOfItems(const char* content) const;


	public:
		Menu(const char* content);
		~Menu();
		Menu(const Menu&) = delete;
		Menu& operator=(const Menu&) = delete;

		unsigned int run() const;
		void display(std::ostream& os) const;
	};
}

#endif // !SDDS_MENU_H
