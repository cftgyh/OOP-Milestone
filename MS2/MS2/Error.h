/*
Final Project Milestone 2
Module: Error header file
Filename: Error.h
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
#ifndef SDDS_ERROR_H
#define SDDS_ERROR_H
#include <iostream>
namespace sdds {
	class Error{
		char* errorMessage{};	// hold error message dynamicly
		// if = null, then no error
		// if != null, then point to one error message

	public:
		Error(const char* eMesssage = NULL);
		~Error();
		// rule of three
		Error(const Error& E);
		Error& operator=(const Error& E);
		operator bool() const;
		Error& clear();
		std::ostream& display(std::ostream& ostr) const;
	};
	std::ostream& operator<<(std::ostream& ostr, const Error& E);
}
#endif // !SDDS_ERROR_H

