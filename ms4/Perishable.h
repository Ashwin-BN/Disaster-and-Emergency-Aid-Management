/* Citation and Sources...
Final Project Milestone 4
Module: Perishable
Filename: Perishable.h
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
#ifndef SDDS_PERISHABLE_H
#define SDDS_PERISHABLE_H

#include "Item.h"
#include "Date.h"

namespace sdds {
    class Perishable : public Item {
    private:
        Date m_expiryDate;
        char* m_handlingInstructions;

        void setEmpty();

    public:
        Perishable();
        Perishable(const Perishable& other);
        Perishable& operator=(const Perishable& other);
        ~Perishable();

        const Date& expiry() const;

        int readSku(std::istream& istr) override;
        std::ofstream& save(std::ofstream& ofstr) const override;
        std::ifstream& load(std::ifstream& ifstr) override;
        std::ostream& display(std::ostream& ostr) const override;
        std::istream& read(std::istream& istr) override;
    };

}
#endif // !SDDS_PERISHABLE_H
