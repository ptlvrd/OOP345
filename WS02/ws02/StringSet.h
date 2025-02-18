/*
Name- Vrundaben vijaykumar patel
id-158605220
email-vvpatel20@myseneca.ca
workshop2-part2
OPP344 section:NCC
date 28/01/2024
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SENECA_STRINGSET_H
#define SENECA_STRINGSET_H
#include <iostream> 

//using namespace std;
namespace seneca {
	class StringSet {
		std::string* array;
		size_t noStrings;
	public:
		StringSet();
		~StringSet();
		StringSet(const char* fileName);
		StringSet(const StringSet& src);
		StringSet& operator=(const StringSet& src);
		StringSet( StringSet&& src);
		StringSet& operator=( StringSet&& src)noexcept;
		size_t size();
		std::string operator[](size_t);

	};
}
#endif // !SENECA_STRINGSET_H
