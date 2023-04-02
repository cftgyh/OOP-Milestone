/*
Final Project Milestone 2
Module: Utils cpp file
Filename: Utils.cpp
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
#include "Utils.h"
using namespace std;

namespace sdds {
    Utils U;
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
    char* Utils::strcat(char* des, const char* src)const {
        int len = strlen(des);
        int i = 0;
        while (src[i]) {
            des[i + len] = src[i];
            i++;
        }
        des[i + len] = char(0);
        return des;
    }
    void Utils::getSystemDate(int& year, int& mon, int& day, int& hour, int& min, bool dateOnly) {
        time_t t = time(NULL);
        tm lt = *localtime(&t);
        day = lt.tm_mday;
        mon = lt.tm_mon + 1;
        year = lt.tm_year + 1900;
        if (dateOnly) {
            hour = min = 0;
        }
        else {
            hour = lt.tm_hour;
            min = lt.tm_min;
        }
    }
    int Utils::uniqueDateValue(int year, int mon, int day, int hour, int min) {
        return year * 535680 + mon * 44640 + day * 1440 + hour * 60 + min;
    }
    int Utils::daysOfMonth(int year, int month) {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = month >= 1 && month <= 12 ? month : 13;
        mon--;
        return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }
}