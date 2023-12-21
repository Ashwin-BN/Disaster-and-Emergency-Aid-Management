/* Citation and Sources...
Final Project Milestone 5 part 3
Module: Perishable
Filename: Perishable.cpp
Author	Ashwin B N
Revision History
-----------------------------------------------------------
Date      Reason
2023/11/29  Preliminary release
2023/11/29  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS

#include "Perishable.h"
#include <cstring>
#include <iomanip>
#include <string>

using namespace sdds;

void Perishable::setEmpty() {
    m_expiryDate = Date();
    delete[] m_handlingInstructions;
    m_handlingInstructions = nullptr;
}

Perishable::Perishable() : Item(), m_expiryDate(), m_handlingInstructions(nullptr) {}

Perishable::Perishable(const Perishable& other) : Item(other), m_handlingInstructions(nullptr)  {
    if (other.m_handlingInstructions != nullptr) {
        m_handlingInstructions = new char[strlen(other.m_handlingInstructions) + 1];
        strcpy(m_handlingInstructions, other.m_handlingInstructions);
    }
    m_expiryDate = other.m_expiryDate;
}

Perishable& Perishable::operator=(const Perishable& other) {
    if (this != &other) {
        Item::operator=(other);
        delete[] m_handlingInstructions;
        if (other.m_handlingInstructions != nullptr) {
            m_handlingInstructions = new char[strlen(other.m_handlingInstructions) + 1];
            strcpy(m_handlingInstructions, other.m_handlingInstructions);
        }
        else {
            m_handlingInstructions = nullptr;
        }
        m_expiryDate = other.m_expiryDate;
    }
    return *this;
}

Perishable::~Perishable() {
    delete[] m_handlingInstructions;
    m_handlingInstructions = nullptr;
}

const Date& Perishable::expiry() const {
    return m_expiryDate;
}

int Perishable::readSku(std::istream& istr) {
    m_state.clear();
    std::cout << "SKU: ";
    m_sku = ut.getint(10000, 39999, nullptr, "Invalid Integer");
    return m_sku;
}

std::ofstream& Perishable::save(std::ofstream& ofstr) const {
    if (m_state) {
        Item::save(ofstr);
        ofstr << "\t";
        if (m_handlingInstructions && m_handlingInstructions[0] != '\0') {
            ofstr << m_handlingInstructions << "\t";
        }
        else {
            ofstr << "\t";
        }
        m_expiryDate.save(ofstr);

        return ofstr;
    }
    return ofstr;
}

std::ifstream& Perishable::load(std::ifstream& ifstr) {
    Item::load(ifstr);

    delete[] m_handlingInstructions;
    m_handlingInstructions = nullptr;
        
    char temp[1000];
    if (ifstr.getline(temp, 1000, '\t') && isalpha(temp[0])) {
        m_handlingInstructions = new char[strlen(temp) + 1];
        strcpy(m_handlingInstructions, temp);
    }
    if (ifstr.fail()) {
        m_state = "Input file stream read (perishable) failed!";
    }

    ifstr >> m_expiryDate;
    if (ifstr.fail()) {
        m_state = "Input file stream read (perishable) failed!";
    }
    else {
        ifstr.ignore();
    }
    return ifstr;
}

std::ostream& Perishable::display(std::ostream& ostr) const {
    if (!m_state) {
        ostr << m_state;
    }
    else {
        if (Item::linear()) {
            Item::display(ostr);

            ostr << (m_handlingInstructions && m_handlingInstructions[0] != '\0' ? '*' : ' ');
            ostr << m_expiryDate; 
        }
        else {
            ostr << "Perishable ";
            Item::display(ostr);
            ostr << "Expiry date: ";
            ostr << m_expiryDate;
            std::cout << std::endl;
            if (m_handlingInstructions && m_handlingInstructions[0] != '\0') {
                ostr << "Handling Instructions: " << m_handlingInstructions << std::endl;
            }
        }
    }
    return ostr;
}

std::istream& Perishable::read(std::istream& istr) {
    Item::read(istr);


    std::cout << "Expiry date (YYMMDD): ";
    istr >> m_expiryDate;

    if (istr.fail()) {
        m_state = "Perishable console date entry failed!";
    }
    else istr.ignore(1000, '\n');

    std::cout << "Handling Instructions, ENTER to skip: ";
    
    char firstChar = istr.peek();
    if (firstChar != '\n') {
        m_handlingInstructions = new char[1000];
        istr.getline(m_handlingInstructions, 1000, '\n');
    }

    if (firstChar == '\n') {
        std::cout << std::endl;
    }

    if (istr.fail()) {
        m_state = "Perishable console date entry failed!";
    }

    return istr;
}