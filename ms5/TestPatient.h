/* Citation and Sources...
Final Project Milestone 5
Module: TestPatient
Filename: TestPatient.h
Version 1.0
Author   
Revision History
-----------------------------------------------------------

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SENECA_TESTPATIENT_H
#define SENECA_TESTPATIENT_H
#include "Patient.h"

namespace seneca {
	extern int nextTestTicket;
	class TestPatient :public Patient {
	public:
		// Default Constructor
		TestPatient();
		char type()const;
		std::ostream& write(std::ostream& ostr = std::cout) const override;
		std::istream& read(std::istream& istr = std::cin)override;
		virtual ~TestPatient() = default;
	};
}
#endif