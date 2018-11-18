#include "DayAppointments.h"

// **construcors**
DayAppointments::DayAppointments(){}
DayAppointments::DayAppointments(int num, string day) {
	numOfAppointments = num;
	appointments = new Appointment [num];
	weekDay = day;
}

// copy constructor
DayAppointments::DayAppointments(const DayAppointments & old) {
	this->setnumOfAppointments ( old.getnumOfAppointments());
	this->setweekday(old.getweekDay());
	this->appointments = new Appointment[old.getnumOfAppointments()];
	for (int i = 0; i < old.numOfAppointments; ++i) {
		this->appointments[i] = old.appointments[i];
	}
}

//overloaded = operator 
DayAppointments& DayAppointments::operator=(DayAppointments& old)
{
	this->numOfAppointments = old.numOfAppointments;
	this->setweekday(old.getweekDay());
	this->appointments = new Appointment[old.numOfAppointments];
	for (int i = 0; i < old.getnumOfAppointments(); i++)
		this->appointments[i] = old.appointments[i];
	return *this;
}

//  **Setters**
void DayAppointments::setweekday(string S) { weekDay = S; }
void DayAppointments::setnumOfAppointments(int n) { numOfAppointments = n; }

// **Getters**
int DayAppointments::getnumOfAppointments()const {	return numOfAppointments; }
string DayAppointments::getweekDay()const { return weekDay; }

// A function to check if two appointments are overloaded
bool DayAppointments::checkoverlapped(int n, Appointment app) {
	if (n == 0)return false;
	bool res=false;

	int h1 = app.getstart().gethour(), h2 = app.getend().gethour();
	int m1 = app.getstart().getminutes(), m2 = app.getend().getminutes();
	int beg1 = (h1 * 100) + m1, end1 = (h2 * 100) + m2;
	string d1 = app.getstart().getdaynight(), d2 = app.getend().getdaynight();
	if (d1 == "PM")beg1 += 120000;
	if (d2 == "PM")end1 += 120000;

	for (int i = 0; i < n; ++i) {

		int h3 = this->appointments[i].getstart().gethour(), h4 = this->appointments[i].getend().gethour();
		int m3 = this->appointments[i].getstart().getminutes(), m4 = this->appointments[i].getend().getminutes();
		int beg2 = (h3 * 100) + m3, end2 = (h4 * 100) + m4;
		string d3 = this->appointments[i].getstart().getdaynight(), d4 = this->appointments[i].getend().getdaynight();
		if (d3 == "PM")beg2 += 120000;
		if (d4 == "PM")end2 += 120000;

		if ( (beg2>=beg1 && beg2<end1) || (end2<=end1 && end2 >beg1 ) ) {
			res = true;
		}
		if(res==true) break;
	}
	return res;
}

// Oustream and istream overloaded operators
ostream& operator<< (ostream& out, DayAppointments app) {
	out << "\nAppointments of " << app.getweekDay()<<" :" << endl;
	for (int i = 1; i <= app.getnumOfAppointments(); ++i) {
		out << "Appointment " << i << ' ' << app.appointments[i-1] << endl;
	}
	return out;
}

istream& operator>> (istream& in, DayAppointments &app) {
	cout << "insert the number of appointments you want in this day :";
	int t;
	cin >> t;
	app.setnumOfAppointments(t);
	app.appointments = new Appointment[app.getnumOfAppointments()];
	cout << "insert the name of the day :";
	string s;
	cin >> s;
	app.setweekday(s);
	cout << "\nPlease enter your "<< app.getnumOfAppointments()<<" Appointments of " << app.getweekDay() << " :" << endl;
	for (int i = 0; i < app.getnumOfAppointments(); ++i) {
		cout << "Appointment number " << i+1 << " :" << endl;
		in >> app.appointments[i];
		if (app.checkoverlapped(i, app.appointments[i])) {
			cout << "This Appointment Is Overlapped ,Please enter a right one " << endl;
			i--;
		}
	}
	return in;
}

bool DayAppointments::operator== (DayAppointments app) {
	bool a = 1;
	if (this->getnumOfAppointments() != app.getnumOfAppointments())a = 0;
	else {
		for (int i = 0; i < this->getnumOfAppointments(); ++i) {
			if (this->appointments[i] != app.appointments[i]) {
				a = 0;
				break;
			}
		}
	}
	return a;
}

bool& DayAppointments::operator!= (DayAppointments app) {
	bool a = !(*this == app);                                  // Using the == overloaded operator and return the inverse
	return a;
}

Appointment DayAppointments::operator[](int n) {
	return (this->appointments[n]);                            // return the index
}

DayAppointments::~DayAppointments(){}
