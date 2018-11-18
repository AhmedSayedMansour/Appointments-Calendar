/// Course:  CS213 - Programming II  - 2018
/// Title:   Assignment 3 - Task 1
/// Program: CS213-2018-A1-T1
/// Author:  Dr. Mohammad El-Ramly
/// Date:    10 August 2018
/* programmers: Ahmed Sayed Mansour           20170022
				Abo-taleb khaled abo-taleb    20170004
*/
/// last edit : 17/11/2018
/// Version: 1.4

#include "Calendar.h"

int main() {
	cout << "Ahlan ya User Ya 7abebe :) \n";
	int deletedapp[100] = { -1 }, cou = 0;
	DayAppointments *Days = new DayAppointments[100];
	Calendar *calendarofDays = new Calendar[100];
	int choise = 0;
	int counterofdays = 0, counterofcalenders = 0;
	bool stop = false;
	while (!stop) {
		cout << "What do you want to do:\n"
			 << "0) Exit.\n"
			 << "1) Insert appointments for a specific day.\n"
			 << "2) Insert appointments for multiple days in the same week.\n"
			 << "3) Display appointments for a specific day.\n"
			 << "4) Display appointments for multiple days in the same week.\n"
			 << "5) Delete appointments of a day.\n"
			 << "6) make the appointments of a day equal to another day. \n"
			 << "Your choice is: ";
		cin >> choise;
		if (choise == 0)stop =true;
		else if (choise == 1) {
			cin >> Days[counterofdays];
			++counterofdays;
		}
		else if (choise == 2) {
			cin >> calendarofDays[counterofcalenders];
			++counterofcalenders;
		}
		else if (choise == 3) {
			int cho;
			cout << "Which day you want to display from your inserted days : " << endl;
			for (int i = 0; i < counterofdays; ++i) {
				bool exist = true;
				for (int j = 0; j < cou; ++j) {
					if (deletedapp[j] == i)	exist = false;
				}
				if (exist)	cout << i + 1 << " ) " << Days[i].getweekDay() << endl;
			}
			cin >> cho;
			if (cho > 0 && cho <= counterofdays) cout << Days[cho-1];
		}
		else if (choise == 4) {
			int ch;
			cout << "Which Week you want to display from your inserted days : " << endl;
			for (int i = 0; i < counterofcalenders; ++i)
				cout << i + 1 << " )Calendar " <<i+1 << endl;
			cin >> ch;
			if (ch > 0 && ch <= counterofcalenders) cout << calendarofDays[ch-1];
		}
		else if (choise == 5) {
			int cho;
			cout << "Which day you want to remove from your inserted days : " << endl;
			for (int i = 0; i < counterofdays; ++i) {
				bool exist = true;
				for (int j = 0; j < cou; ++j) {
					if (deletedapp[j] == i)	exist = false;
				}
				if(exist)	cout << i + 1 << " ) " << Days[i].getweekDay() << endl;
			}
			cin >> cho;
			deletedapp[cou] = cho - 1;
			cou++;
		}
		else if (choise == 6) {
			cout << "\nWhat is the name of the day you want to be copied in :";
			string s;
			cin >> s;
			int choi;
			cout << "\nWhich day you want to be copied from : " << endl;
			for (int i = 0; i < counterofdays; ++i) {
				bool exist = true;
				for (int j = 0; j < cou; ++j) {
					if (deletedapp[j] == i)	exist = false;
				}
				if (exist)	cout << i + 1 << " ) " << Days[i].getweekDay() << endl;
			}
			cin >> choi;
			Days[counterofdays] = Days[choi-1];
			Days[counterofdays].setweekday(s);
			++counterofdays;
			cout << "\n ***Copied***\n";
		}
	}
	// ** deleting pointers ** //
	delete [] Days;
	delete [] calendarofDays;
	system("pause");
}