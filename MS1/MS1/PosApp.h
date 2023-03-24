/*
Final Project Milestone 1
Module: PosApp header file
Filename: PosApp.h
Version 1.0
Date  03/10/2023
Author Xinyu Zhang
Section OOP244-ZAA
Seneca ID   : 174538215
Seneca email: xzhang399@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/
#ifndef SDDS_PROSAPP_H
#define SDDS_PROSAPP_H
#include <iostream>

namespace sdds {
	class PosApp
	{
		char m_fileName[256]{};
	public:
		PosApp(const char* filename);
		void menu();
		void addItem();
		void removeItem();
		void stockItem();
		void listItems();
		void POS();
		void saveRecs();
		void loadRecs();
		void run();
	};
}
#endif // !SDDS_PROSAPP_H

