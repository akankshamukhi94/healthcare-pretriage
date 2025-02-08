#ifndef SENECA_PRETRIAGE_H
#define SENECA_PRETRIAGE_H
#include "Patient.h"
#include "Time.h"
namespace seneca {
	class PreTriage
	{
		Time m_ContagionWaitTime{};
		Time m_TriageWaitTime{};
		Patient* m_lineup[100] = { nullptr };
		char m_dataFilename[256]{};
		int m_numPatients{};

		Time getWaitTime(const Patient& patient)const; 
		int indexOfFirstInLine(char type) const;
		void save() const;
		void lineup() const;
		void setAverageWaitTime(Patient& patient); 
		void load();
		void registerPatient();
		void admit();

	public:
		PreTriage(const char* fileName);
		virtual ~PreTriage();
		void run();
	};
}
#endif