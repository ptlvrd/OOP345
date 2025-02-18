#ifndef SENECA_EMPLOYEE_H
#define SENECA_EMPLOYEE_H
#include "Person.h"
#include <iostream>

namespace seneca {
	class Employee : public Person {
		std::string m_name{};
		std::string m_age{};
		std::string m_id{};
	public:
		//Employee() = default;
		Employee(std::istream& is);
		virtual ~Employee() = default;
		std::string status() const;
		std::string name() const;
		std::string id() const;
		std::string age() const;
		void display(std::ostream& out) const;

	};
}
#endif // !SENECA_EMPLOYEE_H
