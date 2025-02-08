/* Citation and Sources...
Final Project
Module: TriagePatient
Filename: TestPatient.h
Version 1.0
Author   
Revision History

-----------------------------------------------------------*/
#ifndef SENECA_TRIAGEPATIENT_H
#define SENECA_TRIAGEPATIENT_H
#include "Patient.h"

namespace seneca {
	extern int nextTriageTicket;
	class TriagePatient :public Patient {
		char* m_symptoms{};
	public:
		// Default Constructor
		TriagePatient();
		char type()const;
		std::ostream& write(std::ostream& ostr = std::cout) const override;
		std::istream& read(std::istream& istr = std::cin)override;
		~TriagePatient();
	};
}
#endif
