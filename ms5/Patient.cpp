/* Citation and Sources...
Final Project
Module: Patient
Filename: Patient.cpp
Version 1.0
Author   
Revision History
-----------------------------------------------------------

-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include "Patient.h"
#include "Utils.h"
using namespace std;
namespace seneca {
	const int OHIP_MIN = 100000000;
	const int OHIP_MAX = 999999999;
	Patient::Patient(int ticketNumber) : m_patientName{}, m_OHIP{}, m_t(ticketNumber)
	{}

	Patient::Patient(const Patient& P)
	{
		operator=(P);
	}

	Patient& Patient::operator=(const Patient& otherPatient)
	{
		if (this != &otherPatient) {
			delete[] m_patientName;
			m_patientName = new char[strlen(otherPatient.m_patientName) + 1];
			strcpy(m_patientName, otherPatient.m_patientName);
			m_OHIP = otherPatient.m_OHIP;
			m_t = otherPatient.m_t;
		}
		return *this;
	}

	bool Patient::operator==(const char ch) const
	{
		return this->type() == ch;
	}
	bool Patient::operator==(const Patient& otherPatient) const
	{
		return this->type() == otherPatient.type();
	}

	void Patient::setArrivalTime()
	{
		m_t.resetTime();
	}

	Time Patient::time() const {
		return m_t.time();
	}

	unsigned int Patient::number() const
	{
		return m_t.number();
	}

	Patient::operator bool() const
	{
		return m_t.number() != 0;
	}

	Patient::operator const char* () const
	{
		return m_patientName;
	}

// The write method is used to output the patient's information to a given output stream.
std::ostream& Patient::write(std::ostream& ostr) const
{
    // Check if the output stream is the standard logging stream (clog)
    if (&ostr == &clog) {
        // Check if the patient's name is not null, not empty, and the OHIP number is within the valid range
        if (m_patientName && m_patientName[0] && m_OHIP >= 100000000 && m_OHIP <= 999999999) {
            // Format and output the patient's information
            ostr.width(53);
            ostr.setf(ios::left);
            ostr.fill('.');
            ostr << m_patientName;
            ostr.unsetf(ios::left);
            ostr << m_OHIP;
            ostr.fill(' ');
            ostr.setf(ios::right);
            ostr.width(5);
            ostr << m_t.number() << " ";
            ostr.unsetf(ios::right);
            ostr << m_t.time();
        }
        else {
            // Output an error message if the patient's information is invalid
            ostr << "Invalid Patient Record" << endl;
        }
    }
    // Check if the output stream is the standard output stream (cout)
    else if (&ostr == &cout) {
        // Check if the patient's name is not null, not empty, and the OHIP number is not zero
        if (m_patientName && m_patientName[0] && m_OHIP != 0) {
            // Output the patient's information
            ostr << m_t << "\n" << m_patientName << ", OHIP: " << m_OHIP << "\n";
        }
        else {
            // Output an error message if the patient's information is invalid
            ostr << "Invalid Patient Record" << endl;
        }
    }
    else {
        // Output the patient's information in a different format for other output streams
        ostr << this->type() << "," << m_patientName << "," << m_OHIP << ",";
        m_t.write(ostr);
    }
    return ostr;
}

// The read method is used to read the patient's information from a given input stream.
std::istream& Patient::read(std::istream& istr)
{
    // Delete the old patient's name and set it to null
    delete[] m_patientName;
    m_patientName = nullptr;

    char ch[100]{};
    // Check if the input stream is the standard input stream (cin)
    if (&istr == &cin) {
        istr.clear();
        cout << "Name: ";
        istr.get(ch, 51, '\n');
        istr.ignore(1000, '\n');
        // Allocate memory for the new patient's name and copy it from the input buffer
        m_patientName = new char[strlen(ch) + 1];
        strcpy(m_patientName, ch);
        cout << "OHIP: ";
        m_OHIP = U.getIntOHIP(OHIP_MIN, OHIP_MAX);
    }
    else {
        // Read the patient's information from other input streams
        if (istr) {
            istr.clear();
            istr.get(ch, 51, ',');
            istr.ignore(1000, ',');
            // Allocate memory for the new patient's name and copy it from the input buffer
            m_patientName = new char[strlen(ch) + 1];
            strcpy(m_patientName, ch);
            istr >> m_OHIP;
            istr.ignore(100, ',');
            m_t.read(istr);
        }
        else {
            // Delete the patient's name and set it to null if the input stream is not valid
            delete[] m_patientName;
            m_patientName = nullptr;
        }
    }
    return istr;
}

	seneca::Patient::~Patient()
	{
		delete[] m_patientName;
		m_patientName = nullptr;
	}
}
