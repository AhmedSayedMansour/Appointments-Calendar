#pragma once
#include "DayAppointments.h"

class Calendar
{
private:
	DayAppointments * days;
	int numOfDays;
public:
	//  **constructors**
	Calendar();
	Calendar(int n);
	// A function to insert a day to the Calendar
	void InsertDaytoCalendar(DayAppointments Day,int i);
	// istream and oustream overloaded operators
	friend istream& operator >>(istream &, Calendar & calendar);
	friend ostream& operator<< (ostream& out, Calendar calendar);
	~Calendar();
};

