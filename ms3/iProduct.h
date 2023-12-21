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
#ifndef SDDS_IPRODUCT_H
#define SDDS_IPRODUCT_H

#include<iostream>
#include<fstream>


namespace sdds{
	class iProduct {
	public:
        virtual int readSku(std::istream& istr) = 0;
        virtual int operator-=(int qty) = 0;
        virtual int operator+=(int qty) = 0;
        virtual operator double() const = 0;
        virtual operator bool() const = 0;
        virtual int qtyNeeded() const = 0;
        virtual int qty() const = 0;
        virtual void linear(bool isLinear) = 0;
        virtual std::ofstream& save(std::ofstream& ofstr) const = 0;
        virtual std::ifstream& load(std::ifstream& ifstr) = 0;
        virtual std::ostream& display(std::ostream& ostr) const = 0;
        virtual std::istream& read(std::istream& istr) = 0;
        virtual bool operator==(int sku) const = 0;
        virtual bool operator==(const char* description) const = 0;
        virtual ~iProduct() {}
    };

    std::ostream& operator<<(std::ostream& ostr, const iProduct& iprod);
    std::istream& operator>>(std::istream& istr, iProduct& iprod);
}
#endif // !SDDS_IPRODUCT_H
