/*Final Project Milestone 3
Module: iProduct
Filename: iProduct.h
Version 1.0
Author	Ashwin B N
Revision History
-----------------------------------------------------------
Date      Reason
2023/11/20  Preliminary release
2023/11/20  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include "iProduct.h"

namespace sdds{
	std::ostream& operator<<(std::ostream & ostr, const iProduct & iprod) {
		return iprod.display(ostr);
	}

	std::istream& operator>>(std::istream & istr, iProduct & iprod) {
		return iprod.read(istr);
	}
}
