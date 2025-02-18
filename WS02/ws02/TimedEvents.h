/*
Name- Vrundaben vijaykumar patel
id-158605220
email-vvpatel20@myseneca.ca
workshop2-part2
OPP344 section:NCC
date 28/01/2024
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SENECA_TIMEDEVENTS_H
#define SENECA_TIMEDEVENTS_H
#include <chrono>
#include <iostream>
//using namespace std;

namespace seneca {
	const int MAX_EVENTS = 10;

	class TimedEvents {
		int noRecords;
		std::chrono::steady_clock::time_point st;
		std::chrono::steady_clock::time_point et;

		struct {
			std::string eventName;
			std::string timeUnits;
			std::chrono::steady_clock::duration duration;

		}events[MAX_EVENTS];

	public:
		TimedEvents();
		void startClock();
		void stopClock();
		void addEvent(const char* eventname);
		friend std::ostream& operator<<(std::ostream&, const TimedEvents&);

	};
}
#endif // !SENECA_TIMEDEVENTS_H
