/*
Name- Vrundaben vijaykumar patel
id-158605220
email-vvpatel20@myseneca.ca
workshop1-part2
OPP344 section:NCC
date 20/01/2024
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "event.h"
#include <string.h>
#include <iomanip>

using namespace std;

namespace seneca {
	size_t g_sysClock = 0;
	Event::Event() {
		description = nullptr;
		startTime = 0;

	}

	Event::Event(const Event& src) {
		if (src.description != nullptr) {
			description = new char[strlen(src.description) + 1];
			strcpy(description, src.description);
		}
		else {
			description = nullptr;
		}
		startTime = src.startTime;
	}

	Event& Event::operator=(const Event& src) {
		if (this != &src) {
			delete[] description;
			if (src.description != nullptr) {
				description = new char[strlen(src.description) + 1];
				strcpy(description, src.description);
			}
			else {
				description = nullptr;
			}
			startTime = src.startTime;
			
		}
		return *this;
	}

	Event::~Event() {
		delete[] description;
	}

	void Event::display() const {
		static int counter = 1;
		int hour, minute, second;
		hour = startTime / 3600;
		minute = (startTime % 3600) / 60;
		second = startTime % 60;

		cout << setw(2) << setfill(' ') << std::right << counter << ". ";

		if (description == nullptr || description[0] == '\0') {
			cout << "| No Event |" << endl;
		}
		else {
			cout << std::right << setfill('0') << setw(2) << hour << ":";
			cout << std::right << setfill('0') << setw(2) << minute << ":";
			cout << std::right << setfill('0') << setw(2) << second << " => " << description << endl;

		}
		counter++;
	}

	void Event::set(const char* address /* =nullptr*/) {
		if (address != nullptr && address[0] != '\0') {
			delete[] description;
			description = nullptr;
			description = new char[strlen(address) + 1];
			strcpy(description, address);
			startTime = g_sysClock;

		}
		else {
			delete[] description;
			description = nullptr;
			startTime = 0;
		}
	}
}