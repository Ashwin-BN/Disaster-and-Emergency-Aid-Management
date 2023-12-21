/* Citation and Sources...
Final Project Milestone 2
Module: AidMan
Filename: AidMan.h
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
#ifndef AIDMAN_H
#define AIDMAN_H
#include "Menu.h"
namespace sdds {
	class AidMan {
	private:
		char* m_filename;
		Menu m_mainMenu;
		unsigned int menu() const;

	public:
		AidMan(const char* fileName);
		~AidMan();
		AidMan(const AidMan&) = delete;
		AidMan& operator=(const AidMan) = delete;


		void run() const;

	};
}

#endif