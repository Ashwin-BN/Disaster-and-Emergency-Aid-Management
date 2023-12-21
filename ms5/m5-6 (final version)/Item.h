/* Citation and Sources...
Final Project Milestone 5 part 6
Module: Item
Filename: Item.h
Version 1.0
Author	Ashwin B N
Revision History
-----------------------------------------------------------
Date      Reason
2023/11/07  Preliminary release
2023/11/07  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H

#include "iProduct.h"
#include "Status.h"
#include "Utils.h"

namespace sdds {
	class Item : public iProduct {
	private:
		double m_itemPrice;
		int m_quantityOnHand;
		int m_targetedQuantity;
		char* m_itemDescription;
		bool m_isLinear;

	protected:
		Status m_state;
		int m_sku;

		bool linear() const;
		char* readDesc(std::istream& istr);

	public:
		Item();
		Item(const Item& other);
		Item& operator=(const Item& other);
		virtual ~Item();

		int qtyNeeded() const override;
		int qty() const override;
		char* itemDescription() const override;
		operator double() const override;
		operator bool() const override;

		int operator-=(int qty) override;
		int operator+=(int qty) override;
		void linear(bool flag) override;

		void clear();

		bool operator==(int sku) const override;
		bool operator==(const char* description) const override;

		std::ofstream& save(std::ofstream& ofstr) const override;
		std::ifstream& load(std::ifstream& ifstr) override;
		std::ostream& display(std::ostream& ostr) const override;
		
		int readSku(std::istream& istr) override;
		std::istream& read(std::istream& istr) override;
		
	};
}

#endif // !1
