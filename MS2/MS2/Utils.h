/*
Final Project Milestone 2
Module: Utils header file
Filename: Utils.h
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
#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
#include <ctime>
namespace sdds {
	class Utils
	{
	public:
		size_t strlen(const char* str)const;
		char* strcpy(char* des, const char* src)const;
		char* strcat(char* des, const char* src)const;
		void getSystemDate(int& year, int& mon, int& day, int& hour, int& min, bool dateOnly);
		int uniqueDateValue(int year, int mon, int day, int hour, int min);
		int daysOfMonth(int year, int month);
	};
	extern Utils U;
}
#endif // !SDDS_UTILS_H

