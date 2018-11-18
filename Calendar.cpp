#include "Calendar.h"

//constructors
Calendar::Calendar() { }
Calendar::Calendar(int n) {
	days = new DayAppointments[n];
	numOfDays = n;
}

void Calendar::InsertDaytoCalendar(DayAppointments Day, int i) {
	days[i] = Day;
}

istream& operator >>(istream & in, Calendar & calendar) {
	cout << "what is the number of days you want in your calendar :";    //inserting number of days
	int n;
	in >> n;
	calendar.numOfDays = n;
	calendar.days = new DayAppointments[n];
	for (int i = 0; i < calendar.numOfDays; ++i) {
		cout << "\nDay number " << i + 1 << " : \n";                  // inserting the number of a day
		in >> calendar.days[i];
	}
	return in;
}

ostream& operator<< (ostream& out, Calendar calendar) {
	for (int i = 0; i < calendar.numOfDays; ++i) {
		out << calendar.days[i];                                      //display the information of each day
		out << endl;
	}
	return out;
}

Calendar::~Calendar()
{
}
