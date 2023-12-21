/* Citation and Sources...
Final Project Milestone 2
Module: Status
Filename: Status.h
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
#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H

#include <ostream>

namespace sdds {
	class Status {
		char* m_description{};
		int m_code;
	public:
		Status(const char* description = nullptr);
		Status(const Status& other);
		Status& operator=(const Status& other);
		~Status();

		Status& operator=(const char* newDescription);
		Status& operator=(int newCode);

		operator int() const;
		operator const char* () const;
		operator bool() const;

		Status& clear();
	};
	std::ostream& operator<<(std::ostream& ostr, const Status& status);
}

#endif 