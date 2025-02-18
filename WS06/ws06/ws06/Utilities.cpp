#include "Utilities.h"
#include "Employee.h"
#include <iostream>
#include "Student.h"
#include "Professor.h"
#include <sstream>

namespace seneca {
    Person* buildInstance(std::istream& in) {
        std::string line;
        if (!std::getline(in, line)) {
            // Handle end-of-file or stream error
            return nullptr;
        }

        std::stringstream stream(line);
        char ch;
        if (!(stream >> ch)) {
            // Failed to extract character
            return nullptr;
        }

        if (ch == 'e' || ch == 'E') {
            return new Employee(stream);
        }
        else if (ch == 's' || ch == 'S') {
            return new Student(stream);
        }
        else if (ch == 'p' || ch == 'P') {
            return new Professor(stream);
        }
        else {
            return nullptr;
        }
    }

}
