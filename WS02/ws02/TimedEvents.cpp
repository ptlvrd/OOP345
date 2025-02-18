/*
Name- Vrundaben vijaykumar patel
id-158605220
email-vvpatel20@myseneca.ca
workshop2-part2
OPP344 section:NCC
date 28/01/2024
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include "TimedEvents.h"
#include <cstring>
#include <iomanip>
using namespace std;

namespace seneca {
	TimedEvents::TimedEvents() {
		noRecords = 0;
	}

	void TimedEvents::startClock() {
		st = chrono::steady_clock::now();

	}

	void TimedEvents::stopClock() {
		et = chrono::steady_clock::now();

	}

	void TimedEvents::addEvent(const char* eventname) {
		events[noRecords].eventName = eventname;
		events[noRecords].timeUnits = "nanoseconds";
		events[noRecords].duration = std::chrono::duration_cast<std::chrono::nanoseconds>(et - st);
		noRecords++;
	}
	ostream & operator<<(ostream& ostr, const TimedEvents& timedevents) {
		ostr << "--------------------------" << endl;
		ostr << "Execution Times:" << endl;
		ostr << "--------------------------" << endl;

		for (int i = 0; i < timedevents.noRecords; i++) { 
			ostr << std::setw(21) << left << setfill(' ') << timedevents.events[i].eventName;
			ostr << std::setw(13) << right << setfill(' ') << timedevents.events[i].duration.count()<<" ";
			ostr << timedevents.events[i].timeUnits << endl;

		}
		ostr << "--------------------------" << endl;
		return ostr;
	}
}