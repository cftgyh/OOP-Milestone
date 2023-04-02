/*
Final Project Milestone 2
Module: Date cpp file
Filename: Date.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Utils.h"
#include "Error.h"
#include "Date.h"
#include "POS.h"
using namespace std;

namespace sdds {
	Date::Date() {
		m_fDateOnly = false;
		U.getSystemDate(m_year, m_month, m_day, m_hour, m_minute, m_fDateOnly);
	}
	Date::Date(int y, int mon, int d) {
		m_fDateOnly = true;
		m_year = y;
		m_month = mon;
		m_day = d;
		// they are validated now
	}
	Date::Date(int y, int mon, int d, int h, int min) {
		m_fDateOnly = false;
		m_year = y;
		m_month = mon;
		m_day = d;
		m_hour = h;
		m_minute = min;
		// they are validated now
	}
	void Date::setEmpty() {
		m_error.clear();
		m_year = 0;
		m_month = 0;
		m_day = 0;
		m_hour = 0;
		m_minute = 0;
	}
	// comparison operator overloads
	int Date::getDateValue() const {
		return U.uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute);
	}
	bool Date::operator==(const Date& B) const
	{
		return getDateValue() == B.getDateValue();
	}
	bool Date::operator!=(const Date& B) const
	{
		return getDateValue() != B.getDateValue();
	}
	bool Date::operator<(const Date& B) const
	{
		return getDateValue() < B.getDateValue();
	}
	bool Date::operator>(const Date& B) const
	{
		return getDateValue() > B.getDateValue();
	}
	bool Date::operator<=(const Date& B) const
	{
		return getDateValue() <= B.getDateValue();
	}
	bool Date::operator>=(const Date& B) const
	{
		return getDateValue() >= B.getDateValue();
	}
	Date& Date::dateOnly(bool value)
	{
		m_fDateOnly = value;
		if (m_fDateOnly) {
			m_hour = 0;
			m_minute = 0;
		}
		return *this;
	}

	Date::operator bool() const
	{
		return !m_error;
		// return opposite state of error attribute
	}

	const Error& Date::error() const // const1: constant & of error obj
	{								 // const2: does not change Date obj
		return m_error;
	}
	std::ostream& Date::display(std::ostream& ostr) const {
		if (error()) {
			m_error.display(ostr);
			ostr << "(";
		}
		cout.fill('0');
		ostr << m_year;
		ostr << "/";
		cout.width(2);
		ostr << m_month;
		ostr << "/";
		cout.width(2);
		ostr << m_day;
		if (!m_fDateOnly) {
			ostr << ", ";
			cout.width(2);
			ostr << m_hour;
			ostr << ":";
			cout.width(2);
			ostr << m_minute;
		}
		if (error()) {
			ostr << ")";
		}
		return ostr;
	}
	std::istream& Date::read(std::istream& istr) {
		setEmpty();
		int year{}, month{}, day{};
		bool error = false;
		char position[7]{};

		istr >> year;
		if (!istr.fail()) {
			m_year = year;
			istr.ignore();
			istr >> month;
			if (!istr.fail()) {
				m_month = month;
				istr.ignore();
				istr >> day;
				if (!istr.fail()) {
					m_day = day;
					if (!m_fDateOnly) {
						int hour{}, minute{};
						istr.ignore();
						istr >> hour;
						if (!istr.fail()) {
							m_hour = hour;
							istr.ignore();
							istr >> minute;
							if (!istr.fail()) {
								m_minute = minute;
							}
							else {
								error = true;
								U.strcpy(position, "minute");
							}
						}
						else {
							error = true;
							U.strcpy(position, "hour");
						}
					}
					else {
						m_hour = 0;
						m_minute = 0;
					}
				}
				else {
					error = true;
					U.strcpy(position, "day");

				}
			}
			else {
				error = true;
				U.strcpy(position, "month");

			}
		}
		else {
			error = true;
			U.strcpy(position, "year");
		}
		if (error) {
			char message1[100] = "Cannot read ";
			U.strcat(message1, position);
			U.strcat(message1, " entry");

			Error X(message1);
			m_error = X;
		}
		else {
			bool invalid = false;
			char position[20]{};
			if (m_year > MAX_YEAR || m_year < MIN_YEAR) {
				invalid = true;
				U.strcpy(position, "Invalid Year");
			}
			else if (m_month < 1 || m_month > 12) {
				invalid = true;
				U.strcpy(position, "Invalid Month");
			}
			else if (m_day < 1 || m_day > U.daysOfMonth(m_year, m_month)) {
				invalid = true;
				U.strcpy(position, "Invalid Day");
			}
			else if (!m_fDateOnly) {
				if (m_hour < 0 || m_hour > 23) {
					invalid = true;
					U.strcpy(position, "Invalid Hour");
				}
				else if (m_minute < 0 || m_minute > 59) {
					invalid = true;
					U.strcpy(position, "Invlid Minute");
				}
			}
			if (invalid) {
				Error X(position);
				m_error = X;
			}
		}
		return istr;
	}
	std::ostream& operator<<(std::ostream& ostr, const Date& D) {
		return D.display(ostr);
	}
	std::istream& operator>>(std::istream& istr, Date& D) {
		return D.read(istr);
	}
}