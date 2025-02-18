#ifndef SENECA_UTILITIES_H
#define SENECA_UTILITIES_H
#include "Person.h"
#include <iostream>

namespace seneca {

	Person* buildInstance(std::istream& in);
}
#endif // !SENECA_UTILITIES_H
