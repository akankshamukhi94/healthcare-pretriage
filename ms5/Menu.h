/* Citation and Sources...
Final Project
Module: Menu
Filename: Menu.h
Version 1.1
Author   
Revision History
-----------------------------------------------------------
Made the Destructor Virtual
-----------------------------------------------------------*/

#ifndef SENECA_MENU_H
#define SENECA_MENU_H
#include <iostream>
namespace seneca {
	class Menu {
		char* m_text{};
		int m_numOptions{};
		int m_numIndentationTabls{};
		int selectedOption{};
	public:
		Menu(const char* menuContent, int numberOfTabs = 0);
		virtual ~Menu();
		void display() const;
		int& operator>>(int& Selection);
	};
}
#endif
