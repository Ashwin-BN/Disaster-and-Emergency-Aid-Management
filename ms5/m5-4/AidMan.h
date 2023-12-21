/*Final Project Milestone 5 part 4
Module: AidMan
Filename: AidMan.h
Version 1.0
Author	Ashwin B N
Revision History
-----------------------------------------------------------
Date      Reason
2023/11/30  Preliminary release
2023/11/30  Debugged DMA
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
		char* m_fileName;
		Menu m_mainMenu;
		iProduct* m_product[sdds_max_num_items];
		int m_numOfProducts;

		unsigned int menu() const;
		
	private:
		void save() const;
		void deallocate();
		bool load(const char* filename);
		int search(int sku) const;
		void remove(int index);

		void listItems();
		void addItem();
		void removeItem();
		void updateQuantity();

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