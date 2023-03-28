/*
Final Project Milestone 3
Module: Item cpp file
Filename: Item.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Utils.h"
#include "Item.h"
using namespace std;

namespace sdds {
	void Item::setEmpty() {
		m_sku[0] = '\0';
		m_name = nullptr;	// MAX_NAME_LEN
		m_price = 0;
		m_taxed = false;	// if taxable or not
		m_quantity = 0;	// no Of items in the shop
		m_displayType = 0; // POS_LIST = 1; POS_FROM = 2;
		m_error.clear();
	}
	bool Item::isEmpty() const{
		return m_name == nullptr;
	}
	Item::Item():PosIO()
	{
		// set invalid empty state -> empty
		setEmpty();
	}
	// Rule of three
	Item::Item(const Item& I)
	{
		setEmpty();
		cout << I.m_name << "********testing1 I.name********** " << endl;
		*this = I;
	}
	Item::~Item()
	{
		if (m_name) {
			delete[] m_name;
		}
		m_name = nullptr;
	}
	// there are nothing inside M
	Item& Item::operator=(const Item& I)
	{
		if (this != &I && !I.isEmpty()) {
			// size_t length{};
			U.strcpy(m_sku, I.m_sku);
			m_price = I.m_price;
			m_taxed = I.m_taxed;
			m_quantity = I.m_quantity;
			m_displayType = I.m_displayType;

			if (I.m_name != nullptr) {
				if (m_name != nullptr) {
					delete[] m_name;	// error: Invalid free() / delete / delete[] / realloc()
				}
				size_t length = U.strlen(I.m_name);
				// error: invalid read of size 1 error
				m_name = new char[length + 1];
				U.strcpy(m_name, I.m_name);
			}
		}
		else {
			m_name = nullptr;
		}
		return *this;
	}
	// Member operators
	bool Item::operator==(const char* string) const
	{
		return !U.strcmp(m_sku, string); //non-0: true; 0: false
	}
	bool Item::operator>(const Item& I) const
	{
		return U.strcmp(m_name, I.m_name) > 0;
	}
	int Item::operator+=(int value)
	{
		m_quantity += value;
		if (m_quantity > MAX_STOCK_NUMBER) {
			m_quantity = MAX_STOCK_NUMBER;
			m_error.clear();
			m_error = ERROR_POS_QTY;
		}
		return m_quantity;
	}
	int Item::operator-=(int value)
	{
		if (value > m_quantity) {
			m_quantity = 0;
			m_error.clear();
			m_error = ERROR_POS_STOCK;
		}
		else {
			m_quantity -= value;
		}
		return m_quantity;
	}
	Item::operator bool() const
	{
		return !m_error;
	}
	// Member functions
	Item& Item::displayType(const int dType)
	{
		m_displayType = dType;
		return *this;
	}
	double Item::cost() const
	{
		double value{};
		if (m_taxed) value = m_price * (1 + TAX);
		else value = m_price;

		return value;
	}
	int Item::quantity() const
	{
		return m_quantity;
	}
	Item& Item::clear()
	{
		m_error.clear();
		return *this;
	}
	std::ostream& Item::write(std::ostream& ostr) const
	{
		if (!isEmpty()) {
			if (m_error) {
				m_error.display(ostr);
			}
			else {
				char name[21]{};
				if (m_name != nullptr) U.strcpy(name, m_name, 20);

				ostr.setf(ios::fixed);
				ostr.precision(2);

				if (m_displayType == POS_LIST) {
					cout.setf(ios::left);
					ostr.width(7);
					ostr << m_sku;
					ostr << "|";
					ostr.width(20);
					ostr << name;
					cout.unsetf(ios::left);
					ostr << "|";
					ostr.width(7);
					ostr << m_price;
					ostr << "| ";
					ostr.width(2);
					if (m_taxed) ostr << "X";
					else ostr << " ";
					ostr << "|";
					ostr.width(4);
					ostr << m_quantity;
					ostr << "|";
					ostr.width(9);
					ostr << (cost() * m_quantity);
					ostr << "|";
				}
				else if (m_displayType == POS_FORM) {
					ostr.fill('=');
					ostr.width(13);
					ostr << '=';
					ostr << "V" << endl;
					ostr << "Name:        " << m_name << endl;
					ostr << "Sku:         " << m_sku << endl;
					ostr << "Price:       " << m_price << endl;
					ostr << "Price + tax: ";
					if (m_taxed) {
						ostr << cost();
					}
					else {
						ostr << "N/A";
					}
					ostr << endl;
					ostr << "Stock Qty:   " << m_quantity << endl;
				}
			}
		}
		return ostr;
	}
	/* output.csv for save() function
	T,1234,Screw Driver,12.32,1,89
	T,2345,The Claw Hammer,15.21,0,49
	T,3456,Utility Knife,20.10,1,59
	T,4567,Tape Measure - Level - Laser - Combo,112.30,0,9
	T,1111,Chisel,10.00,0,9
	*/
	// save no error
	std::ofstream& Item::save(std::ofstream& ofst) const
	{
		if (!isEmpty()) {
			if (m_error) {
				cerr << m_error << endl;
			}
			else {
				ofst.setf(ios::fixed);
				ofst.precision(2);
				ofst << "T" << ",";
				ofst << m_sku << ",";
				ofst << m_name << ",";
				ofst << m_price << ",";
				ofst << m_taxed << ",";
				ofst << m_quantity;
			}
		}
		return ofst;
	}
	// >>
	std::istream& Item::read(std::istream& istr)
	{
		char taxed{};
		char sku[4096]{};
		char temp[4096]{};
		cout << "Sku" << endl << "> ";
		istr >> sku;
		/* max_sku_len = 7, however, if enter 8chars, 
		it will get the first 7chars instead of cin.fail() */
		while (istr.fail() || U.strlen(sku) > MAX_SKU_LEN) {
			istr.clear();
			istr.ignore(10000, '\n');
			cout << ERROR_POS_SKU << endl << "> ";
			istr >> sku;
		}
		istr.ignore(10000, '\n');
		U.strcpy(m_sku, sku);

		if (this->m_name) {
			delete[] m_name;
			m_name = nullptr;
		}
		cout << "Name" << endl << "> ";
		// istr >> name; use cin.getline(...) to read space-seperated string, istr can only read before space
		istr.getline(temp, 4096);

		while (U.strlen(temp) > MAX_NAME_LEN) {
			cout << ERROR_POS_NAME << endl << "> ";
			istr.getline(temp, 4096);
		}
		m_name = U.aloCopy(U.strlen(temp), temp);
	/*	m_name = new char[U.strlen(temp) + 1];
		U.strcpy(m_name, temp);*/


		cout << "Price" << endl << "> ";
		istr >> m_price;
		while (istr.fail() || m_price < 0) {
			istr.clear();
			istr.ignore(10000, '\n');
			cout << ERROR_POS_PRICE << endl << "> ";
			istr >> m_price;
		}

		cout << "Taxed?" << endl << "(Y)es/(N)o: ";
		istr >> taxed;
		while (istr.fail() || (taxed != 'y' && taxed != 'n')) {
			istr.clear();
			istr.ignore(10000, '\n');
			cout << "Only 'y' and 'n' are acceptable: ";
			istr >> taxed;
		}
		taxed == 'y' ? m_taxed = true : m_taxed = false;

		cout << "Quantity" << endl << "> ";
		istr >> m_quantity;

		while (istr.fail() || (m_quantity <= 0 || m_quantity > MAX_STOCK_NUMBER)) {
			istr.clear();
			istr.ignore(10000, '\n');
			cout << ERROR_POS_QTY << endl << "> ";
			istr >> m_quantity;
		}
		return istr;
	}
	// load from file (T, already been read)
	/*
	T,1234,Screw Driver,12.32,1,90
	T,2345,The Claw Hammer,15.21,0,50
	T,3456,Utility Knife,20.10,1,60
	T,4567,Tape Measure - Level - Laser - Combo, 112.30,0,10
	*/
	std::ifstream& Item::load(std::ifstream& ifst)
	{
		char sku[4096]{};
		char name[4096]{};
		double price{};
		bool taxed{};	
		int quantity{};
		m_error.clear();
		//setEmpty();

		ifst.getline(sku, 4096, ',');
		if (U.strlen(sku) <= MAX_SKU_LEN && U.strlen(sku) > 0) {
			U.strcpy(m_sku, sku);

			ifst.getline(name, 4096, ',');
			if (name != nullptr && U.strlen(name) <= MAX_NAME_LEN) {
				if (m_name) {
					delete[] m_name;
				}
				m_name = new char[U.strlen(name) + 1];
				U.strcpy(m_name, name);

				ifst >> price;
				if (!ifst.fail() && price > 0) {
					m_price = price;
					ifst.ignore();

					ifst >> taxed;
					if (!ifst.fail()) {
						m_taxed = taxed;
						ifst.ignore();

						ifst >> quantity;
						if (!ifst.fail() && quantity > 0 && quantity <= MAX_STOCK_NUMBER) {
							m_quantity = quantity;
						}
						else {
							ifst.clear();
							m_error = ERROR_POS_QTY;
						}
					}
					else {
						ifst.clear();
						m_error = ERROR_POS_TAX;
					}
				}
				else {
					ifst.clear();
					m_error = ERROR_POS_PRICE;
				}
			}
			else {
				ifst.clear();
				m_error = ERROR_POS_NAME;
			}
		}
		else {
			ifst.clear();
			m_error = ERROR_POS_SKU;
		}

		return ifst;
	}
	std::ostream& Item::bprint(std::ostream& ostr) const
	{
		char name[21]{};
		U.strcpy(name, m_name, 20);

		cout.fill(' ');
		cout.setf(ios::left);
		ostr << "|";
		ostr.width(20);
		ostr << name;
		cout.unsetf(ios::left);
		ostr << "|";
		ostr.width(11);
		ostr << cost();
		ostr << "| ";
		ostr.width(5);
		if (m_taxed) ostr << "T";
		else ostr << " ";
		ostr << "|" << endl;
		
		return ostr;
	}
	// Helper function
	double operator+=(double& value, const Item& I)
	{
		value += (I.cost() * I.quantity());
		return value;
	}
}
