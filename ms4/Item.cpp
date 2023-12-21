/* Citation and Sources...
Final Project Milestone 3
Module: Item
Filename: Item.cpp
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
#define _CRT_SECURE_NO_WARNINGS

#include <iomanip>
#include <cstring>
#include "Item.h"
#include <string>

using namespace sdds;

bool Item::linear() const {
	return m_isLinear;
}

Item::Item()
    : m_itemPrice(0.0), m_quantityOnHand(0), m_targetedQuantity(0), m_itemDescription(nullptr),
    m_isLinear(false), m_sku(0) {
    m_state.clear();
}

Item::Item(const Item& other) : m_itemPrice(other.m_itemPrice), m_quantityOnHand(other.m_quantityOnHand),
m_targetedQuantity(other.m_targetedQuantity), m_itemDescription(nullptr), m_isLinear(other.m_isLinear) {
    m_state = other.m_state;
    m_sku = other.m_sku;
    if (other.m_itemDescription != nullptr) {
        m_itemDescription = new char[strlen(other.m_itemDescription) + 1];
        strcpy(m_itemDescription, other.m_itemDescription);
    }
}

Item& Item::operator=(const Item& other) {
    if (this != &other) {
        m_itemPrice = other.m_itemPrice;
        m_quantityOnHand = other.m_quantityOnHand;
        m_targetedQuantity = other.m_targetedQuantity;
        m_isLinear = other.m_isLinear;
        m_state = other.m_state;
        m_sku = other.m_sku;

        delete[] m_itemDescription;
        if (other.m_itemDescription != nullptr) {
            m_itemDescription = new char[strlen(other.m_itemDescription) + 1];
            strcpy(m_itemDescription, other.m_itemDescription);
        }
        else {
            m_itemDescription = nullptr;
        }
    }
    return *this;
}

Item::~Item() {
    delete[] m_itemDescription;
    m_itemDescription = nullptr;
}

int Item::qtyNeeded() const {
    return m_targetedQuantity;
}

int Item::qty() const {
    return m_quantityOnHand;
}

Item::operator double() const {
    return m_itemPrice;
}

Item::operator bool() const {
    return m_state && m_itemDescription != nullptr;
}

int Item::operator-=(int qty) {
    if (qty > 0) {
        m_quantityOnHand -= qty;
    }
    return m_quantityOnHand;
}

int Item::operator+=(int qty) {
    if (qty > 0) {
        m_quantityOnHand += qty;
    }
    return m_quantityOnHand;
}

void Item::linear(bool flag) {
    m_isLinear = flag;
}

void Item::clear() {
    m_state.clear();
}

bool Item::operator==(int sku) const {
    return m_sku == sku;
}

bool Item::operator==(const char* description) const {
    if (description == nullptr || m_itemDescription == nullptr) {
        return false;
    }

    return (strstr(m_itemDescription, description) != nullptr);
}


std::ofstream& Item::save(std::ofstream& ofstr) const {
    if (operator bool()) {
        ofstr << m_sku << "\t" << m_itemDescription << "\t" << m_quantityOnHand << "\t" << m_targetedQuantity << "\t"
            << std::fixed << std::setprecision(2) << m_itemPrice << "\t";
    }
    return ofstr;

}

std::ifstream& Item::load(std::ifstream& ifstr) {
    delete[] m_itemDescription;
    m_itemDescription = nullptr;
    char temp[2000];

    ifstr >> m_sku;
    if (ifstr.fail()) {
        m_state = "Input file stream read failed!";
        return ifstr;
    }
    ifstr.ignore();

    ifstr.getline(temp, 2000, '\t');
    m_itemDescription = new char[strlen(temp) + 1];
    strcpy(m_itemDescription, temp);

    ifstr >> m_quantityOnHand;
    if (ifstr.fail()) {
        m_state = "Input file stream read failed!";
    }
    else {
        ifstr.ignore();
    }

    ifstr >> m_targetedQuantity; 
    if (ifstr.fail()) {
        m_state = "Input file stream read failed!";
    }
    else {
        ifstr.ignore();
    }

    ifstr >> m_itemPrice;
    if (ifstr.fail()) {
        m_state = "Input file stream read failed!";
    }
    else {
        ifstr.ignore(1); 
    }
    return ifstr;
}

std::ostream& Item::display(std::ostream& ostr) const {
    if (!operator bool()) {
        ostr << m_state;
    }
    else {
        if (m_isLinear) {
            ostr << std::setw(5) << m_sku << " | "
                << std::left << std::setw(35) << std::setfill(' ') 
                << (std::strlen(m_itemDescription) > 35 ? std::string(m_itemDescription, 35) : m_itemDescription)
                << " | " << std::right << std::setw(4) << m_quantityOnHand << " | "
                << std::right << std::setw(4) << m_targetedQuantity << " | "
                << std::right << std::setw(7) << std::setprecision(2) << m_itemPrice << " |";
        }
        else {
            ostr << "AMA Item:" << std::endl
                << std::setw(5) << m_sku << ": "
                << m_itemDescription << std::endl
                << "Quantity Needed: " << m_targetedQuantity << std::endl
                << "Quantity Available: " << m_quantityOnHand << std::endl
                << "Unit Price: $" << std::fixed << std::setprecision(2) << m_itemPrice << std::endl
                << "Needed Purchase Fund: $" << std::fixed << std::setprecision(2) << (m_targetedQuantity * m_itemPrice) - (m_quantityOnHand * m_itemPrice) << std::endl;
        }
    }
    return ostr;
}

int Item::readSku(std::istream& istr) {
    m_state.clear();
    std::cout << "SKU: ";
    m_sku = ut.getint(40000, 99999, nullptr, "Invalid Integer");
    return m_sku;
}

std::istream& Item::read(std::istream& istr) {
    delete[] m_itemDescription;
    m_itemDescription = nullptr;
    m_state.clear();

    std::cout << "AMA Item:" << std::endl;
    m_sku = readSku(istr);
    istr.ignore(1000, '\n');

    // Read Description
    char desc[2000];
    std::cout << "Description: ";
    istr.getline(desc, 2000);
    if (istr.fail()) {
        m_state = "Console entry failed!";
        return istr;
    }
    m_itemDescription = new char[strlen(desc) + 1];
    strcpy(m_itemDescription, desc);
    

    // Read Quantity Needed
    if (!istr.fail()) {
        std::cout << "Quantity Needed: ";
        m_targetedQuantity = ut.getint(1, 9999, nullptr, "Invalid Integer");
    }
    else {
        m_state = "Console entry failed!";
        return istr;
    }

    // Read Quantity On Hand
    if (!istr.fail()) {
        std::cout << "Quantity On Hand: ";
        m_quantityOnHand = ut.getint(0, m_targetedQuantity, nullptr, "Invalid Integer");
    }
    else {
        m_state = "Console entry failed!";
        return istr;
    }

    // Read Unit Price
    if (!istr.fail()) {
        std::cout << "Unit Price: $";
        m_itemPrice = ut.getDouble(0.0, 9999.0, nullptr, "Invalid number");
    }
    else {
        m_state = "Console entry failed!";
        return istr;
    }

    
    if (istr.fail()) {
        m_state = "Console entry failed!";
    }

    return istr;
}
