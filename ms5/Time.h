/* Citation and Sources...
Final Project
Module: Time
Filename: Time.h
Version 1.0
Author   
Revision History
-----------------------------------------------------------*/
#ifndef SENECA_TIME_H
#define SENECA_TIME_H

#include <iostream>

namespace seneca {
    class Time {
        int m_numMins{};

    public:
        Time& reset();

        // Constructors and Destructors
        Time(unsigned int min = 0u);

        // Read and Write Functions
        std::ostream& displayMethod(std::ostream& ostr = std::cout) const;
        std::istream& readMethod(std::istream& istr = std::cin);

        // Operator Overloads
        operator unsigned int() const;
        Time& operator*=(int val);
        Time& operator-=(const Time& D);
        Time operator-(const Time& T) const;
        virtual ~Time() = default;
    };

    std::ostream& operator<<(std::ostream& ostr, const Time& T);
    std::istream& operator>>(std::istream& istr, Time& T);
} // namespace seneca

#endif
