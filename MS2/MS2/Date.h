/*
Final Project Milestone 2
Module: Date header file
Filename: Date.h
Version 1.0
Date  03/17/2023
Author Xinyu Zhang
Section OOP244-ZAA
Seneca ID   : 174538215
Seneca email: xzhang399@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/
#ifndef SDDS_DATE_H
#define SDDS_DATE_H
#include <iostream>
#include "Error.h"
#include "Utils.h"
namespace sdds {
	class Date
	{
		int m_year{};
		int m_month{};
		int m_day{};
		int m_hour{};
		int m_minute{};
		bool m_fDateOnly{};	// flag for using date only
		Error m_error{};		// keep track of operation success
		int getDateValue() const;
	public:
		Date();
		Date(int y, int mon, int d);
		Date(int y, int mon, int d, int h, int min = 0);
		void setEmpty();
		// comparison operator overloads 
		bool operator==(const Date& B)const;
		bool operator!=(const Date& B)const;
		bool operator<(const Date& B)const;
		bool operator>(const Date& B)const;
		bool operator<=(const Date& B)const;
		bool operator>=(const Date& B)const;
		Date& dateOnly(bool value);
		operator bool() const;
		// error query function
		const Error& error() const;	
		std::ostream& display(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);
	};
	std::ostream& operator<<(std::ostream& ostr, const Date& D);
	std::istream& operator>>(std::istream& istr, Date& D);
}
#endif // !SDDS_DATE_H

