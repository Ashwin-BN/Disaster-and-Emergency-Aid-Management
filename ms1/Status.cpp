/* Citation and Sources...
Final Project Milestone 1
Module: Status
Filename: Status.cpp
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


#include <iostream>
#include <cstring>
#include "Status.h"
#include "Utils.h"

using namespace std;
namespace sdds {
    Status::Status(const char* description) {
        m_code = 0;
        if (description) {
            ut.alocpy(m_description, description);
        }
    }

    Status::Status(const Status& other) {
        if (other.m_description){
            ut.alocpy(m_description, other.m_description);
            m_code = other.m_code;
        }
        else {
            clear();
        }
    }

    Status& Status::operator=(const Status& other) {
        if (this != &other){
            clear();
            m_code = other.m_code;
            if (other.m_description != nullptr){
                ut.alocpy(m_description, other.m_description);
            }
        }
        return *this;
    }

    Status::~Status() {
        clear();
    }

    Status& Status::operator=(const char* newDescription) {
        if (newDescription){
            ut.alocpy(m_description, newDescription);
        }
        return *this;
    }

    Status& Status::operator=(int newCode) {
        m_code = newCode;
        return *this;
    }

    Status::operator int() const {
        return m_code;
    }

    Status::operator const char* () const {
        return m_description;
    }

    Status::operator bool() const {
        return !m_description;
    }

    Status& Status::clear() {
        delete[] m_description;
        m_description = nullptr;
        m_code = 0;
        return *this;
    }

    std::ostream& operator<<(std::ostream& ostr, const Status& status) {
        if (!bool(status)) {
            if (int(status) != 0) {
                ostr << "ERR#" << int(status) << ": ";
            }
            ostr << (const char*)(status);
        }
        return ostr;
    }

}