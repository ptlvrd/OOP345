#include "Employee.h"
#include <iostream>
#include <iomanip>

namespace seneca {
	Employee::Employee(std::istream& is){
		std::string tag{};
		is.ignore(1);

		std::getline(is, tag);
		size_t startIndex = 0;
		size_t endIndex = tag.find(',');

		m_name = tag.substr(startIndex, (endIndex - startIndex));
		m_name.erase(0, m_name.find_first_not_of(" \t\r\n"));
		m_name.erase(m_name.find_last_not_of(" \t\r\n") + 1);
		startIndex = endIndex + 1;
		endIndex = tag.find(',', startIndex);

		m_age = tag.substr(startIndex, (endIndex - startIndex));
		m_age.erase(0, m_age.find_first_not_of(" \t\r\n"));
		m_age.erase(m_age.find_last_not_of(" \t\r\n") + 1);
		for (auto& ch : m_age) {
			if (std::isdigit(ch) == 0) {
				throw std::string(m_name + "++Invalid record!");
			}
		}
		startIndex = endIndex + 1;
		endIndex = tag.find(',', startIndex);

		// Extract and validate the student ID
		m_id = tag.substr(startIndex, (endIndex - startIndex));
		m_id.erase(0, m_id.find_first_not_of(" \t\r\n"));
		m_id.erase(m_id.find_last_not_of(" \t\r\n") + 1);
		if (m_id[0] != 'E') {
			throw std::string(m_name + "++Invalid record!");
		}


		
	}


	std::string Employee::status() const
	{
		return "Employee";
	}

	std::string Employee::name() const
	{
		return m_name;
	}

	std::string Employee::id() const
	{
		return m_id;
	}

	std::string Employee::age() const
	{
		return m_age;
	}

	void Employee::display(std::ostream& out) const {
		out << "| " << std::left << std::setw(10) << "Employee" << "| "
			<< std::left << std::setw(10) << m_id << "| "
			<< std::left << std::setw(20) << m_name << " | "
			<< std::left << std::setw(3) << m_age << " |";
	}
}