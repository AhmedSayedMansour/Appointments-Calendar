#include "Time.h"
#include <iostream>

using namespace std;

//A constructor with defaukt values
Time::Time()
{
	hour = 12;
	minute = 0;
	daynight="AM";
}


//A constructor that takes all data members
Time::Time(int hours, int min, string m) {
	hour = hours;
	minute= min ;
	daynight = m ;
}

//Copy Constructor
Time::Time(const Time & t) {
	sethour(t.gethour());
	setminutes(t.getminutes())  ;
	setdaynight (t.getdaynight()) ;
}

//     **Getters**
int Time::gethour()const { return hour; }
int Time::getminutes()const { return minute; }
string Time::getdaynight()const { return daynight; }

//     **Setters**
void Time::sethour(int h) { hour = h; }
void Time::setminutes(int m) { minute = m; }
void Time::setdaynight(string d) { daynight = d; }

//     Oustream overloaded operator
ostream&  operator<< (ostream& out, Time time)
{
	out << time.gethour() << ":" << time.getminutes() << " " << time.getdaynight() << endl;
	return out;
}

//   Istream overloaded operator
istream& operator>> (istream& in, Time& time)
{
	int h, m;
	string d;
	cout << "Enter hour :" << endl;
	in >> h;
	time.sethour(h);
	cout << "Enter min :" << endl;
	in >> m;
	time.setminutes( m);
	cout << "enter the daynight :" << endl;
	in >> d;
	time.setdaynight( d);
	return in;
}

bool Time::operator<(Time time) {
	if (this->daynight == "PM" && time.daynight == "AM") return 0;
	else if (this->daynight == "AM" && time.daynight == "PM") return 1;
	else {
		if (this->hour < time.hour)	return 1;                 //check both hours
		else if (this->hour > time.hour)return 0;
		else {
			if (this->minute < time.minute)	return 1;		  //check minutes
			else return 0;
		}
	}
}

bool& Time::operator>(Time time) {
	bool a=!(*this < time);           // Using overloaded operator < and return the not value
	return a;	
}

bool Time::operator==(Time time) {
	bool equal = ((this->hour==time.hour) && (this->minute==time.minute) && (this->daynight==time.daynight));
	return equal;
}

bool& Time::operator!=(Time time) {
	bool equal = !(*this == time);      // Using overloaded operator == and return the not value
	return equal;
}

Time::~Time()
{
}
