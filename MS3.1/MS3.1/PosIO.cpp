/*
Final Project Milestone 3
Module: PosIO cpp file
Filename: PosIO.cpp
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
#include "PosIO.h"
using namespace std;

namespace sdds {
	std::ostream& operator<<(std::ostream& ostr, const PosIO& P)
	{
		return P.write(ostr);
	}
	std::ofstream& operator<<(std::ofstream& ofst, const PosIO& P)
	{
		return P.save(ofst);
	}
	std::istream& operator>>(std::istream& istr, PosIO& P)
	{
		P.read(istr);
		return istr;
	}
	std::ifstream& operator>>(std::ifstream& ifst, PosIO& P)
	{
		return P.load(ifst);
	}
}