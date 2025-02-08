/* Citation and Sources...
Final Project Milestone 4
Module: IOAble
Filename: IOAble.cpp
Version 1.0
Author   
Revision History
-----------------------------------------------------------

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include <iostream>
#include "IOAble.h"
using namespace std;
namespace seneca {
	std::ostream& operator<<(std::ostream& ostr, const IOAble& obj)
	{
		return obj.write(ostr);
	}
	std::istream& operator>>(std::istream& istr, IOAble& obj)
	{
		return obj.read(istr);
	}
}