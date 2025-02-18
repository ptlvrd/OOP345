#include "Professor.h"
#include <iostream>
#include <iomanip>

namespace seneca {
	Professor::Professor(std::istream& in) : Employee(in) {
        char comma;
        in >> comma;
        std::getline(in, m_department, ',');
        m_department.erase(0, m_department.find_first_not_of(" \t\r\n"));
        m_department.erase(m_department.find_last_not_of(" \t\r\n") + 1);
    }


    void Professor::display(std::ostream& out) const {
        Employee::display(out);
        out << m_department << "| Professor";
    }

    std::string Professor::status() const { 
        return "Professor"; 
    }

    std::string Professor::department() const { 
        return m_department;
    }


  

}