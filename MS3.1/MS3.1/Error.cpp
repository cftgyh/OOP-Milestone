/*
Final Project Milestone 3
Module: Error cpp file
Filename: Error.cpp
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
#include "Error.h"
using namespace std;

namespace sdds {
	Error::Error(const char* eMessage)
	{
		if (eMessage) {
			errorMessage = new char[U.strlen(eMessage) + 1];
			U.strcpy(errorMessage, eMessage);
		}
	}
	Error::~Error() {
		if (errorMessage) {
			delete[] errorMessage;
		}
		errorMessage = nullptr;
	}
	Error::Error(const Error& E) {
		errorMessage = nullptr;
		operator=(E);
	}
	Error& Error::operator=(const Error& E) {
		if (this != &E) {
			if (errorMessage) {
				delete[] errorMessage;
			}
			errorMessage = nullptr;
			if (E.errorMessage) {
				errorMessage = new char[U.strlen(E.errorMessage) + 1];
				U.strcpy(errorMessage, E.errorMessage);
			}
		}
		return *this;
	}
	Error::operator bool() const {
		return errorMessage != nullptr;
	}
	Error& Error::clear() {
		if (errorMessage) {
			delete[] errorMessage;
		}
		errorMessage = nullptr;

		return *this;
	}
	std::ostream& Error::display(std::ostream& ostr) const
	{
		if (errorMessage) {
			ostr << errorMessage;
		}
		return ostr;
	}
	std::ostream& operator<<(std::ostream& ostr, const Error& E)
	{
		return E.display(ostr);
	}
}