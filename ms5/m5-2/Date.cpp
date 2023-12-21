/* Citation and Sources...
Final Project Milestone 2
Module: Date
Filename: Date.cpp
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
#include <iostream>
#include <iomanip>

#include "Date.h"
#include "Utils.h"

namespace sdds {

    bool Date::validate() {
        int currentYear;
        ut.getSystemDate(&currentYear);

        if (m_year == 0 && m_month == 0 && m_day == 0) {
            m_state = "Invalid date value";
            return false;
        }
        else if (m_year < currentYear || m_year > MAX_YEAR_VALUE) {
            m_state = "Invalid year in date";
            m_state = 1;
            return false;
        }
        else if (m_month < 1 || m_month > 12) {
            m_state = "Invalid month in date";
            m_state = 2;
            return false;
        }
        else if (m_day < 1 || m_day > ut.daysOfMon(m_month, m_year)) {
            m_state = "Invalid day in date";
            m_state = 3;
            return false;
        }

        m_state.clear();
        return true;
    }

    int Date::uniqueDateValue() const {
        return m_year * 372 + m_month * 31 + m_day;
    }

    Date::Date(int year, int month, int day) : m_year(year), m_month(month), m_day(day), m_formatted(true) {
        if (year == 0 || month == 0 || day == 0) {
            ut.getSystemDate(&m_year, &m_month, &m_day);
        }
        validate();
    }

    bool Date::operator==(const Date& right) const {
        return this->uniqueDateValue() == right.uniqueDateValue();
    }

    bool Date::operator!=(const Date& right) const {
        return this->uniqueDateValue() != right.uniqueDateValue();
    }

    bool Date::operator<(const Date& right) const {
        return this->uniqueDateValue() < right.uniqueDateValue();
    }

    bool Date::operator>(const Date& right) const {
        return this->uniqueDateValue() > right.uniqueDateValue();
    }

    bool Date::operator<=(const Date& right) const {
        return this->uniqueDateValue() <= right.uniqueDateValue();
    }

    bool Date::operator>=(const Date& right) const {
        return this->uniqueDateValue() >= right.uniqueDateValue();
    }

    const Status& Date::state() const {
        return m_state;
    }

    Date& Date::formatted(bool value) {
        m_formatted = value;
        return *this;
    }

    Date::operator bool() const {
        return m_state;
    }

    std::ostream& Date::write(std::ostream& ostr) const {
        if (m_formatted) {
            ostr << m_year << '/';
            ostr << std::setfill('0') << std::setw(2) << m_month << '/';
            ostr << std::setfill('0') << std::setw(2) << m_day;
        }
        else {
            ostr << std::setfill('0') << std::setw(2) << m_year % 100;
            ostr << std::setw(2) << m_month << std::setw(2) << m_day;
        }
        return ostr;
    }

    std::istream& Date::read(std::istream& istr) {
        int dateInput, currentYear;
        ut.getSystemDate(&currentYear);

        istr >> dateInput;

        if (!istr.fail()) {
            if (dateInput <= 9999) {
                m_day = dateInput % 100;
                m_month = dateInput / 100;
                m_year = currentYear;
            }
            else if (dateInput >= 100000 && dateInput <= 999999) {
                m_day = dateInput % 100;
                m_month = (dateInput / 100) % 100;
                m_year = (dateInput / 10000) + ((currentYear / 100) * 100);
            }
        }
        else {
            m_day = 0;
            m_month = 0;
            m_year = 0;
        }

        if (!validate()) {
            istr.setstate(std::ios::badbit);
        }

        return istr;
    }

    std::ostream& Date::save(std::ostream& ostr) const {
    ostr << std::setfill('0') << std::setw(2) << m_year % 100;
    ostr << std::setw(2) << m_month << std::setw(2) << m_day;
    return ostr;
}

    std::ostream& operator<<(std::ostream& ostr, const Date& date) {
        return date.write(ostr);
    }
    std::istream& operator>>(std::istream& istr, Date& date) {
        return date.read(istr);
    }

}
