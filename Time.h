#pragma once
#include <iostream>
#include <string>

using namespace std;

class Time
{
private:
	//Data members
	int hour;
	int minute;
	string daynight;
public:

	//An empty constractor
	Time();
	//A constructor that takes the details of the time
	Time(int hours ,int min,string m);
	//Copy constractor
	Time(const Time & t);
	//A function to get the #of hours
	int gethour()const;
	//A function to get the #of minutes
	int getminutes()const;
	//A function to get the daynight
	string getdaynight()const;
	//A function to set the #of hours
	void sethour(int h);
	//A function to set the #of minutes
	void setminutes(int m);
	//A function to set the daynight
	void setdaynight(string d);
	//Oustream overloaded operator
	friend ostream&  operator<< (ostream& out, Time time);
	//istream overloaded operator
	friend istream& operator>> (istream& in, Time& time);
	//A function that ensure if the first time is lower than the second
	bool operator<(Time time);
	//A function that ensure if the first time is bigger than the second
	bool& operator>(Time time);
	//A function that ensure if the first time is equal to the second
	bool operator==(Time time);
	//A function that ensure if the first time is is not equal to the second
	bool& operator!=(Time time);
	//Destructor
	~Time();
};

