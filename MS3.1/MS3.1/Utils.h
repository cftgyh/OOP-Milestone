/*
Final Project Milestone 3
Module: Utils header file
Filename: Utils.h
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
#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

namespace sdds {
	class Utils
	{
	public:
		size_t strlen(const char* str)const;
		char* strcpy(char* des, const char* src)const;
		char* strcpy(char* des, const char* src, int len)const;
		char* strcat(char* des, const char* src)const;
		int strcmp(const char* s1, const char* s2)const;
		char* aloCopy(size_t length, const char* src)const;
	};
	extern Utils U;
}
#endif // !SDDS_UTILS_H



