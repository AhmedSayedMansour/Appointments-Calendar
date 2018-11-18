#include "Appointment.h"

// ***constructors***
Appointment::Appointment(){}
Appointment::Appointment(Time s, Time e) {
	start = s;
	end = e;
}
Appointment::Appointment(const Appointment & t) {
	start = t.getstart();
	end = t.getend();
}

// A function to calculate the interval to make it eazier in the compartion
double Appointment::calinterval() {

	double endtime = 0; 
	if (end.gethour() == 12) {
		if(end.getdaynight() == "AM")	endtime = end.getminutes();
		else endtime = 1200 + end.getminutes();
	}
	else {
		if (end.getdaynight() == "AM")	endtime = end.getminutes()+end.gethour()*100;
		else endtime = 1200 + end.getminutes() + end.gethour() * 100;
	}

	int starttime = 0;
	if (start.gethour() == 12) {
		if(start.getdaynight() == "AM")	starttime = start.getminutes();
		else starttime = 1200 + start.getminutes();
	}
	else {
		if (start.getdaynight() == "AM")	starttime = start.getminutes()+end.gethour()*100;
		else starttime = 1200 + start.getminutes() + start.gethour() * 100;
	}

	return ((endtime - starttime) / 100.0);
}

//  ** Gettres**
Time Appointment::getstart()const {
	return start;
}
Time Appointment::getend()const {
	return end;
}

//oustream overloaded operator
ostream&  operator<< (ostream& out, Appointment appointment) {
	out << endl << "interval start from " << appointment.getstart().gethour() << ':' << appointment.getstart().getminutes() << ' '
		<< appointment.getstart().getdaynight() << " To " << appointment.getend().gethour() << ':'
		<< appointment.getend().getminutes() << " " << appointment.getend().getdaynight() << endl;
	return out;
}

//istream overloaded operator
istream& operator>> (istream& in, Appointment &appointment) {
	int x, y, z, w;
	string a, b;
	cout << endl << "enter start time hour : ";
	in >> x;
	cout << endl << "enter start time minutes : ";
	in >> y;
	cout << endl << "enter start time daynight : ";
	in >> a;
	appointment.start.sethour(x);
	appointment.start.setminutes(y);
	appointment.start.setdaynight(a);
	cout << endl << "enter end time hour : ";
	in >> z;
	cout << endl << "enter end time minutes : ";
	in >> w;
	cout << endl << "enter end time daynight : ";
	in >> b;
	appointment.end.sethour(z);
	appointment.end.setminutes(w);
	appointment.end.setdaynight(b);

	return in;
}


bool Appointment::operator==(Appointment app) {
	bool equal = ((start == app.start) && (end==app.end));
	return equal;
}

bool Appointment::operator!=(Appointment app) {
	bool notequal = !(*this == app);        //Using the == overloaded operator
	return notequal;
}

bool Appointment::operator<(Appointment app) {
	if (calinterval() < app.calinterval())	return 1;
	else return 0;
}

bool Appointment::operator>(Appointment app) {
	if (calinterval() > app.calinterval())	return 1;       //Using the < overloaded operator
	else return 0;
}

bool Appointment::operator>=(Appointment app) {
	if (this->calinterval() >= app.calinterval())	return 1;
	else return 0;
}

bool Appointment::operator<=(Appointment app) {
	if (calinterval() <= app.calinterval())	return 1;    //Using the >=overloaded operator
	else return 0;
}

//The destructor
Appointment::~Appointment()
{
}
