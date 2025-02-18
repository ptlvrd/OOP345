#include "College.h"
#include <iostream>
#include <iomanip>

namespace seneca {
    College& College::operator+=(Person* thePerson){
        m_persons.push_back(thePerson);
        return *this;
    }

    College::~College() {
        for (auto person : m_persons) {
            delete person;
        }
    }


    void College::display(std::ostream& out) const {
        out << "------------------------------------------------------------------------------------------------------------------------" << '\n';
        out << "|                                        Test #1 Persons in the college!                                               |" << '\n';
        out << "------------------------------------------------------------------------------------------------------------------------" << '\n';
        for (auto i = m_persons.begin(); i != m_persons.end(); ++i)
        {
            (*i)->display(out);
            std::cout << std::endl;
        }

        out << "------------------------------------------------------------------------------------------------------------------------" << '\n';
        out << "|                                        Test #2 Persons in the college!                                               |" << '\n';
        out << "------------------------------------------------------------------------------------------------------------------------" << '\n';

        for (auto i = m_persons.begin(); i != m_persons.end(); i++) {
            out << std::left
                << "| " << std::setw(10) << (*i)->status() << "| "
                << std::setw(10) << (*i)->id() << "| "
                << std::setw(20) << (*i)->name() << " | "
                << std::setw(3) << (*i)->age() << " |"
                << std::endl;
        }

        out << "------------------------------------------------------------------------------------------------------------------------" << '\n';
    }
}