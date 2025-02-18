/*
Name- Vrundaben vijaykumar patel
id-158605220
email-vvpatel20@myseneca.ca
workshop1-part2
OPP344 section:NCC
date 20/01/2024
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H

//int g_sysClock;
namespace seneca {

	extern size_t g_sysClock;
	class Event {
		char* description;
		unsigned int startTime;
	public:
		Event();
		void display() const;
		void set(const char* address = nullptr);
		Event(const Event& src);
		Event& operator=(const Event& src);
		~Event();
	};
}
#endif // !SENECA_EVENT_H
