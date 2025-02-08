/* Citation and Sources...
Final Project Milestone 5
Module: IOAble
Filename: IOAble.h
Version 1.0
Author   
Revision History
-----------------------------------------------------------

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SENECA_IOABLE_H
#define SENECA_IOABLE_H
#include <iostream>
namespace seneca {
	// Pure-Abstract Base class OR Interface
	class IOAble {
	public:
		// Pure Virtual Functions
		// Pure virtual function for future ostream outputs
		virtual std::ostream& write(std::ostream& ostr = std::cout) const = 0;
		// Pure virtual function for future istream inputs
		virtual std::istream& read(std::istream& istr = std::cin) = 0;

		// Empty Virtual Destructor
		virtual ~IOAble() = default;
	};
	// Overloading the insertion operator (<<)
	std::ostream& operator<<(std::ostream& ostr, const IOAble& obj);
	// Overloading the extraction operator (>>)
	std::istream& operator>>(std::istream& istr, IOAble& obj);
}
#endif // !SENECA_IOABLE_
