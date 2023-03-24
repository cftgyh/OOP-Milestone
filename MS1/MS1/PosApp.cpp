/* 
Final Project Milestone 1
Module: PosApp cpp file
Filename: PosApp.cpp
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
#include "PosApp.h"
#include "Utils.h"
using namespace std;

namespace sdds {
	PosApp::PosApp(const char* filename) {
		if (U.strlen(filename) < 256) {
			U.strcpy(m_fileName, filename);
		}
	}
	void PosApp::menu() {
		cout << "The Sene-Store" << endl;
		cout << "1- List items" << endl;
		cout << "2- Add item" << endl;
		cout << "3- Remove item" << endl;
		cout << "4- Stock item" << endl;
		cout << "5- Point of Sale" << endl;
		cout << "0- exit program" << endl;	
	}
	void PosApp::addItem() {
		cout << ">>>> Adding Item to the store................................................" << endl;
		cout << "Running addItem()" << endl;
	}
	void PosApp::removeItem() {
		cout << ">>>> Remove Item............................................................." << endl;
		cout << "Running removeItem()" << endl;
	}
	void PosApp::stockItem() {
		cout << ">>>> Select an item to stock................................................." << endl;
		cout << "Running stockItem()" << endl;
	}
	void PosApp::listItems() {
		cout << ">>>> Listing Items..........................................................." << endl;
		cout << "Running listItems()" << endl;
	}
	void PosApp::POS() {
		cout << ">>>> Starting Point of Sale.................................................." << endl;
		cout << "Running POS()" << endl;
	}
	void PosApp::saveRecs() {
		cout << ">>>> Saving Data............................................................." << endl;
		cout << "Saving data in " << m_fileName << endl;
	}
	void PosApp::loadRecs() {
		cout << ">>>> Loading Items..........................................................." << endl;
		cout << "Loading data from " << m_fileName << endl;
	}
	void PosApp::run() {
		int value{};
		bool invInput{}; // invalid input
		bool invInt{};	 // invalid int
		loadRecs();
		do {
			menu();
			cout << "> ";
			do {
				invInput = !U.read(value);
				if (invInput) {
					cout << "Invalid Integer, try again: ";
				}
				else {
					invInt = value < 0 || value > 5;
					if (invInt) {
						cout << "[0<=value<=5], retry: > ";
					}
				}
			} while (invInput || invInt);

			if (value == 1) {
				listItems();
			}
			else if (value == 2) {
				addItem();
			}
			else if (value == 3) {
				removeItem();
			}
			else if (value == 4) {
				stockItem();
			}
			else if (value == 5) {
				POS();
			}
		} while (value != 0);
		saveRecs();
		cout << "Goodbye!" << endl;
	}
}
