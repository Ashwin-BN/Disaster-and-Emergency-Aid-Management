/* Citation and Sources...
Final Project Milestone 1
Module: Date
Filename: Date.h
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
#ifndef SDDS_DATE_H
#define SDDS_DATE_H

const int MAX_YEAR_VALUE = 2030;

#include <iostream>

#include "Utils.h"
#include "Status.h"

namespace sdds {
	class Date {
		int m_year;
		int m_month;
		int m_day;
		Status m_state;
		bool m_formatted;

		bool validate();
		int uniqueDateValue() const;

	public:
        Date(int year = 0, int month = 0, int day = 0);

        bool operator==(const Date& right) const;
        bool operator!=(const Date& right) const;
        bool operator<(const Date& right) const;
        bool operator>(const Date& right) const;
        bool operator<=(const Date& right) const;
        bool operator>=(const Date& right) const;

        // state accessor
        const Status& state() const;

        // formatted modifier
        Date& formatted(bool value);

        operator bool() const;

        std::ostream& write(std::ostream& ostr) const;
        std::istream& read(std::istream& istr);

    };

    std::ostream& operator<<(std::ostream& ostr, const Date& date);
    std::istream& operator>>(std::istream& istr, Date& date);

}

#endif 