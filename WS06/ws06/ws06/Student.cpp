#include "Student.h"
#include <iostream>
#include <iomanip>
#include <sstream>

namespace seneca {
    Student::Student(std::istream& is) {
        std::string tag{};
        is.ignore(1);

        std::getline(is, tag);

        size_t startIndex = 0;
        size_t endIndex = tag.find(',');

        // Extract and clean the name
        m_name = tag.substr(startIndex, (endIndex - startIndex));
        m_name.erase(0, m_name.find_first_not_of(" \t\r\n"));
        m_name.erase(m_name.find_last_not_of(" \t\r\n") + 1);

        startIndex = endIndex + 1;
        endIndex = tag.find(',', startIndex);

        // Extract and validate the age
        m_age = tag.substr(startIndex, (endIndex - startIndex));
        m_age.erase(0, m_age.find_first_not_of(" \t\r\n"));
        m_age.erase(m_age.find_last_not_of(" \t\r\n") + 1);
        for (auto& ch : m_age) {
            if (!std::isdigit(ch)) {
                throw std::string(m_name + "++Invalid record!");
            }
        }

        startIndex = endIndex + 1;
        endIndex = tag.find(',', startIndex);

        // Extract and validate the student ID
        m_id = tag.substr(startIndex, (endIndex - startIndex));
        m_id.erase(0, m_id.find_first_not_of(" \t\r\n"));
        m_id.erase(m_id.find_last_not_of(" \t\r\n") + 1);
        if (tolower(m_id[0]) != 's') {
            throw std::string(m_name + "++Invalid record!");
        }

        startIndex = endIndex + 1;
        endIndex = tag.find(',', startIndex);

        // Extract and validate the number of courses
        std::string count_courses_str = tag.substr(startIndex, (endIndex - startIndex));
        count_courses_str.erase(0, count_courses_str.find_first_not_of(" \t\r\n"));
        count_courses_str.erase(count_courses_str.find_last_not_of(" \t\r\n") + 1);
        for (auto& ch : count_courses_str) {
            if (!std::isdigit(ch)) {
                throw std::string(m_name + "++Invalid record!");
            }
        }
        m_count = std::stoi(count_courses_str);

        // Extract and clean the courses
        m_courses = new std::string[m_count];
        for (int i = 0; i < m_count; i++) {
            std::getline(is, m_courses[i], ','); // Use the correct delimiter here
            // Store the course directly
            m_courses[i].erase(0, m_courses[i].find_first_not_of(" \t\r\n"));
            m_courses[i].erase(m_courses[i].find_last_not_of(" \t\r\n") + 1);
        }

    }

	Student::~Student() {
		delete[] m_courses;
	}

	std::string Student::status() const {
		return "Student";
	}

	std::string Student::name() const {
		return m_name;
	}

	std::string Student::age() const {
		return m_age;
	}

	std::string Student::id() const {
		return m_id;
	}

	void Student::display(std::ostream& out) const {
		out << "| " << std::left << std::setw(10) << "Student" << "| "
			<< std::left << std::setw(10) << m_id << "| "
			<< std::left << std::setw(20) << m_name << " | "
			<< std::left << std::setw(3) << m_age << " | ";
		for (int i = 0; i < m_count; i++) {
			out << m_courses[i];
			if (i < m_count - 1) {
				out << ", ";
			}
		}

	}

}