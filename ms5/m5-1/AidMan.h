/*Final Project Milestone 2
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
#include "iProduct.h"
#include "Item.h"
#include "Perishable.h"

namespace sdds {
	const int sdds_max_num_items = 100;

	class AidMan {
	private:
		char* m_fileName;
		Menu m_mainMenu;
		iProduct* m_product[sdds_max_num_items];
		int m_numOfProducts;

		unsigned int menu() const;
		
	private:
		void save() const;
		void deallocate();
		bool load(const char* filename);

	public:
		AidMan(const char* fileName = nullptr);
		~AidMan();
		AidMan(const AidMan&) = delete;
		AidMan& operator=(const AidMan) = delete;


		void run() ;
		int list(const char* sub_desc = nullptr) const;
	};
}

#endif