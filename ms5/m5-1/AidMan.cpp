/* Citation and Sources...
Final Project Milestone 5 part 1
Module: AidMan
Filename: AidMan.cpp
Version 1.0
Author	Ashwin B N
Revision History
-----------------------------------------------------------
Date      Reason
2023/11/13  Preliminary release
2023/11/13  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "AidMan.h"
#include "Utils.h"
#include "Date.h"

namespace sdds {

    AidMan::AidMan(const char* fileName) : m_fileName(nullptr), m_mainMenu("List Items\tAdd Item\tRemove Item\tUpdate Quantity\tSort\tShip Items\tNew/Open Aid Database"), m_numOfProducts(0) {
		if (fileName && strlen(fileName) > 0) {
			ut.alocpy(m_fileName, fileName);
		}
	}

	AidMan::~AidMan() {
        delete[] m_fileName;
        m_fileName = nullptr;
        deallocate();
	}


	void AidMan::run() {
		while (true){
            int numRow = 0;
            int numPrinted = 0;

			unsigned int choice = menu();

            if (choice != 0 && m_fileName == nullptr && choice != 7) {
                choice = 7;
            }

            switch (choice) {
            case 0:
                std::cout << "Exiting Program!" << std::endl;
                save();
                return;
            case 1:
                std::cout << "\n****List Items****\n";
                
                numRow = list();
                do {
                    std::cout << "Enter row number to display details or <ENTER> to continue:" << std::endl;
                    std::cout << "> ";
                    std::cin.ignore();
                    if (std::cin.peek() == '\n') {

                        std::cout << "\n";
                        break;
                    }
                    std::cin >> numPrinted;
                    if (numPrinted >= 1 && numPrinted <= numRow) {
                        m_product[numPrinted - 1]->linear(false);
                        m_product[numPrinted - 1]->display(std::cout);
                        std::cout << '\n' << '\n';

                    }
                    else {
                        std::cout << "Invalid input. Please enter a valid row number." << std::endl;
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                    }

                    std::cin.ignore();

                } while (numPrinted <= 1 && numPrinted >= numRow);

                break;
            case 2:
                std::cout << "\n****Add Item****\n\n";
                break;
            case 3:
                std::cout << "\n****Remove Item****\n\n";
                break;
            case 4:
                std::cout << "\n****Update Quantity****\n\n";
                break;
            case 5:
                std::cout << "\n****Sort****\n\n";
                break;
            case 6:
                std::cout << "\n****Ship Items****\n\n";
                break;
            case 7:
                std::cout << "\n****New/Open Aid Database****\n";
                std::cout << "Enter file name: ";
                char newFileName[256];
                std::cin >> newFileName;
                load(newFileName);
                break;
            default:
                std::cout << "Invalid option!" << std::endl;
            }
		}
	}

	unsigned int AidMan::menu() const {
		Date date(0,0,0);
		std::cout << "Aid Management System" << std::endl;
		std::cout << "Date: ";
		date.write(std::cout) << std::endl;
		std::cout << "Data file: " << (m_fileName ? m_fileName : "No file") << std::endl;
        std::cout << "---------------------------------" << std::endl;
		return m_mainMenu.run();
	}

    void AidMan::save() const {
        if (m_fileName) {
            std::ofstream outfile(m_fileName);
            if (outfile.is_open()) {
                for (int i = 0; i < m_numOfProducts; i++) {
                    m_product[i]->save(outfile);
                    outfile << '\n';
                }
            }
            else {
                std::cerr << "Failed to open file " << m_fileName << " for writing!" << std::endl;
            }
        }
    }

    void AidMan::deallocate() {
        for (int i = 0; i < m_numOfProducts; i++) {
            delete m_product[i];
            m_product[i] = nullptr;
        }
        m_numOfProducts = 0;
    }

    bool AidMan::load(const char* filename) {
        if (m_fileName) {
            delete[] m_fileName;
            m_fileName = nullptr;
        }
        if (filename != nullptr && filename[0] != '\0') {
            m_fileName = new char[strlen(filename) + 1];
            strcpy(m_fileName, filename);
        }

        std::ifstream ifstr(m_fileName);
        if (!ifstr.is_open()) {
            std::cout << "Failed to open" << m_fileName << "for reading!" << std::endl;
            std::cout << "Would you like to create a new data file?" << std::endl;
            std::cout << "1- Yes!" << std::endl;
            std::cout << "0- Exit" << std::endl;
            int choice = 0;
            std::cin >> choice;
            if (choice == 1) {
                std::ofstream outfile(m_fileName);
                if (!outfile.is_open()) {
                    std::cout << "Failed to create new data file!" << std::endl;
                    return false;
                }
                outfile.close();
            }
            return false;
        }

        // reading data from the input file 
        while (!ifstr.eof() && m_numOfProducts < sdds_max_num_items) {
            // perishable products
            if (ifstr.peek() >= '1' && ifstr.peek() <= '3') {
                m_product[m_numOfProducts] = new Perishable;
            }
            // non-perishable products
            else if (ifstr.peek() >= '4' && ifstr.peek() <= '9') {
                m_product[m_numOfProducts] = new Item;
            }
            else {
                ifstr.clear();
                ifstr.ignore(1000, '\n');
                continue;
            }

            m_product[m_numOfProducts]->load(ifstr);

            if (*m_product[m_numOfProducts]) {
                m_numOfProducts++;
            }
        }
        if (this) {
            std::cout << m_numOfProducts << " records loaded!\n" << std::endl;
        }
        save();
        return (m_numOfProducts > 0);
    }


    int AidMan::list(const char* sub_desc) const {
        int rowNum = 0;
        std::cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << std::endl;
        std::cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << std::endl;
        
        for (int i = 0; i < m_numOfProducts; i++) {
            if (sub_desc == nullptr) {
                m_product[i]->linear(true);
                std::cout << "   " << i + 1 << " | ";
                m_product[i]->display(std::cout);
                rowNum++;
                std::cout << std::endl;
            }
            else if (sub_desc) {
                std::cout << "   " << i + 1 << " | ";
                m_product[i]->display(std::cout);
                rowNum++;
                std::cout << std::endl;
            }
        }
        std::cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << std::endl;
        return rowNum;
    }
}
