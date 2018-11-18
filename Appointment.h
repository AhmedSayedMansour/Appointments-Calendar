#pragma once
#include "Time.h"

class Appointment
{
private:
	Time start;
	Time end;
	int interval;
public:
	//Default constructor
	Appointment();
	//A constructor that takes both times
	Appointment(Time s,Time e);
	//Copy constructor
	Appointment(const Appointment & t);
	//A function to calculate interval
	double calinterval();
	//  **Getters**
	Time getstart()const;
	Time getend()const;
	//  **overloaded iostream and oustream operators**
	friend ostream&  operator<< (ostream& out, Appointment appointment);
	friend istream& operator>> (istream& in, Appointment &appointment);
	/********** Required overloaded operators ************/
	bool operator==(Appointment app);
	bool operator!=(Appointment app);
	bool operator<(Appointment app);
	bool operator>(Appointment app);
	bool operator>=(Appointment app);
	bool operator<=(Appointment app);
	//Destructor
	~Appointment();
};

