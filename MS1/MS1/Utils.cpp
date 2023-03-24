/*
Final Project Milestone 1
Module: Utils cpp file
Filename: Utils.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "Utils.h"
using namespace std;

namespace sdds {
    Utils U; 
    bool Utils::read(int& val) {
        bool res{ true };
        cin >> val;
        if (cin.fail())    
        {
            res = false;
            cin.clear();    
            cin.ignore(100000, '\n');
        }
        return res;
    }
    size_t Utils::strlen(const char* str)const {
        size_t len{};
        for (len = 0; str[len]; len++);
        return len;
    }
    char* Utils::strcpy(char* des, const char* src)const {
        size_t i{};
        for (i = 0; src[i]; i++) {
            des[i] = src[i];
        }
        des[i] = char(0); // char(0) represents null character.
        return des;
    }
}
