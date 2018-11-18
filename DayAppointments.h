#pragma once
#include "Appointment.h"

class DayAppointments
{
private:
	Appointment* appointments;
	int numOfAppointments;
	string weekDay;		// like Saturday, Monday … etc
public:
	//Constructors
	DayAppointments();
	DayAppointments(int num,string day);
	//Copy constructors
	DayAppointments(const DayAppointments & old);
	DayAppointments& operator=(DayAppointments&);
	//       **Setters**
	void setweekday(string S);
	void setnumOfAppointments(int n);
	//       **Getters**
	int getnumOfAppointments()const;
	string getweekDay()const;
	// A function to check if two appointments are overlapped
	bool checkoverlapped(int n, Appointment app);
	// istream and ostream overloaded operators
	friend ostream&  operator<< (ostream& out, DayAppointments app);
	friend istream& operator>> (istream& in, DayAppointments &app);
	// overloaded == and != and [] overloaded operators
	bool operator== ( DayAppointments app);
	bool& operator!= ( DayAppointments app);
	Appointment operator[](int n);
	//Destructor
	~DayAppointments();
};

