/*
Name- Vrundaben vijaykumar patel
id-158605220
email-vvpatel20@myseneca.ca
workshop2-part2
OPP344 section:NCC
date 28/01/2024
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNIGS
#include <iostream>
#include "StringSet.h"
#include <fstream>
#include <string>
using namespace std;

namespace seneca {
	StringSet::StringSet() {
		array = nullptr;
		noStrings = 0;

	}

	StringSet::StringSet(const char* fileName) : array(nullptr), noStrings(0){
		std::ifstream inputFile(fileName);
		std::string line;

		while (getline(inputFile, line, ' ')) {
			noStrings++;
		}
		inputFile.clear();
		inputFile.seekg(0);
		array = new string[noStrings];
		size_t index = 0;
		while (index<noStrings && std::getline(inputFile, line, ' ')) {
			array[index++] = line;
		}

		inputFile.close();
	}

	StringSet::StringSet(const StringSet& src) : array(nullptr), noStrings(0){

		noStrings=src.noStrings;
        array = new std::string[noStrings];
        for(size_t i = 0; i < noStrings; i++) {
        array[i] = src.array[i];
		}
	}

	StringSet& StringSet::operator=(const StringSet& src) {
		if (this != &src) {
			delete[] array;
			noStrings = src.noStrings;
			array = new string[src.noStrings];
			for (size_t i = 0; i < noStrings; i++) {
				array[i] = src.array[i];
			}
		}
		return *this;
	}

	StringSet::StringSet(StringSet&& src):array(src.array), noStrings(src.noStrings){
		src.array = nullptr;
		src.noStrings = 0;
	}

	StringSet& StringSet::operator=(StringSet&& src) noexcept {
		if (this != &src) {
			delete[] array;
			array = nullptr;
			noStrings = src.noStrings;
			array = src.array;
			src.array = nullptr;
			src.noStrings = 0;

		}
		return *this;
	}

	StringSet::~StringSet() {
		delete[] array;
	}

	size_t StringSet::size() {
		return noStrings;
	}

	string StringSet::operator[](size_t index) {
		if (index < noStrings) {
			return array[index];

		}return "";
	}
}
