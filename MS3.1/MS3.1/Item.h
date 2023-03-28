/*
Final Project Milestone 3
Module: Item header file
Filename: Item.h
Version 1.0
Date  03/24/2023
Author Xinyu Zhang
Section OOP244-ZAA
Seneca ID   : 174538215
Seneca email: xzhang399@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/
#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H
#include <iostream>
#include <fstream>
#include "POS.h"
#include "Error.h"
#include "PosIO.h"

namespace sdds {
	class Item: public PosIO{
		char m_sku[MAX_SKU_LEN]{};	// don't + 1!!!!!!!!!!!!!!!!!
		char* m_name{};	// MAX_NAME_LEN
		double m_price{};
		bool m_taxed{};	// if taxable or not
		int m_quantity{};	// no Of items in the shop
	protected:
		int m_displayType{}; // POS_LIST = 1; POS_FROM = 2;
		Error m_error{};
		void setEmpty();
		bool isEmpty() const;
	public:
		Item();
		// Rule of three
		Item(const Item& I);
		~Item();
		Item& operator=(const Item& I);
		// Member operators
		bool operator==(const char* string)const;
		bool operator>(const Item& I)const;
		int operator+=(int value);
		int operator-=(int value);
		operator bool() const;
		// Member functions
		Item& displayType(const int dType);
		double cost() const;
		int quantity()const;
		Item& clear();
		std::ostream& write(std::ostream& ostr) const;
		std::ofstream& save(std::ofstream& ofst) const;
		std::istream& read(std::istream& istr);
		std::ifstream& load(std::ifstream& ifst);
		std::ostream& bprint(std::ostream& ostr)const;
	};
	double operator+=(double& value, const Item& I);
}
#endif // !SDDS_ITEM_H

