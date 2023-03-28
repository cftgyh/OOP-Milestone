/*
Final Project Milestone 3
Module: PosIO header file
Filename: PosIO.h
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
#ifndef SDDS_POSIO_H
#define SDDS_POSIO_H
#include <iostream>
#include <fstream>

namespace sdds {
	// the class as an interface for console and file input/output operations
	class PosIO
	{
	public:
		virtual std::ostream& write(std::ostream& ostr) const = 0;
		virtual std::ofstream& save(std::ofstream& ofst) const = 0;

		virtual std::istream& read(std::istream& istr) = 0;
		virtual std::ifstream& load(std::ifstream& ifst) = 0;
		virtual ~PosIO() {};
	};
	std::ostream& operator<<(std::ostream& ostr, const PosIO& P);
	std::ofstream& operator<<(std::ofstream& ofst, const PosIO& P);

	std::istream& operator>>(std::istream& istr, PosIO& P);
	std::ifstream& operator>>(std::ifstream& ifst, PosIO& P);
}
#endif // !SDDS_POSIO_H


