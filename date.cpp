//NAME: Brandon Hahn
//SECTION: 4

#include <iostream>
#include "date.h"
#include <string>
#include <iomanip>

using namespace std;


Date::Date()
{
	month = 1;
	day = 1;
	year = 2000;
	format = 'D';
}

Date::Date(int m, int d, int y)
{
//checks to make sure that it's a valid date
	int monthArr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if ((y % 4 == 0 && y % 100 !=0) || y % 400 == 0)
		monthArr[1] = 29;
	if (m > 12 || m < 1) {
		month = 1;
		day = 1;
		year = 2000;
	} else if(d > monthArr[m-1] || d < 1) {
		month = 1;
		day = 1;
		year = 2000;
	} else if(y < 0) {
		month = 1;
		day = 1;
		year = 2000;
	} else {
		month = m;
		day = d;
		year = y;
	}
	format = 'D';
}

void Date::Input()
{
//basically the same as the previous function
//except the keyboard monkey does the hard work
	int m, d, y;
	char slash;
	cout << "Enter a date: ";
	cin >> m >> slash >> d >> slash >> y;
	int monthArr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
		monthArr[1] = 29;
	if (m > 12 || m < 1)
	{
		month = 1;
		day = 1;
		year = 2000;
	} else if(d > monthArr[m-1] || d < 1) {
		month = 1;
		day = 1;
		year = 2000;
	} else if (y < 0) {
		month = 1;
		day = 1;
		year = 2000;
	} else {
		month = m;
		day = d;
		year = y;
	}
}

void Date::Show()
{
	//this array is only necessary for the Julian part
	int monthArr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		monthArr[1] = 29;
//easiest one of all, yay default
	if (format == 'D')
		cout << month << '/' << day << '/' << year << endl;
//i know for a fact that there is a MUCH easier way to do this
//but basically this accounts for every possible type of date
//i hope
	else if (format == 'T'){
		if (month > 9){
			if (day > 9){
				if (year > 9 && year < 100){
					cout << month << '/' << day << '/' << year << endl;
				} else if(year <= 9){
					cout << month << '/' << day << "/0" << year << endl;
				} else if(year % 100 <= 9 && year % 100 > 0){
					cout << month << '/' << day << "/0" << year % 100 << endl;
				}else if(year % 100 == 0){
					cout << month << '/' << day << "/00" << endl;
				} else
					cout << month << '/' << day << '/' << (year % 100) << endl;
				}
			else{
				if (year > 9 && year < 100){
					cout << month << "/0" << day << '/' << year << endl;
				} else if(year <= 9){
					cout << month << "/0" << day << "/0" << year << endl;
				} else if(year % 100 <= 9){
					cout << month << "/0" << day << "/0" << year % 100 << endl;
				} else if(year % 100 == 0){
					cout << month << "/0" << day << "/00" << endl;
				} else
					cout << month << "/0" << day << '/' << (year % 100) << endl;
			}
		}
		else{
			if (day > 9){
				if (year > 9 && year < 100){
					cout << '0' << month << '/' << day << '/' << year << endl;
				} else if(year <= 9){
					cout << '0' << month << '/' << day << "/0" << year << endl;
				} else if(year % 100 <= 9 && year % 100 > 0){
					cout << '0' << month << '/' << day << "/0" << year % 100 << endl;
				} else if (year % 100 == 0){
					cout << '0' << month << '/' << day << "/00" << endl;
				} else
					cout << '0' << month << '/' << day << '/' << (year % 100) << endl;
				}
			else{
				if (year > 9 && year < 100){
					cout << '0' << month << "/0" << day << '/' << year << endl;
				} else if (year <= 9){
					cout << '0' << month << "/0" << day << "/0" << year << endl;
				} else if(year % 100 <= 9 && year % 100 > 0){
					cout << '0' << month << "/0" << day << "/0" << year % 100 << endl;
				} else if (year % 100 == 0){
					cout << '0' << month << "/0" << day << "/00" << endl;
				} else
					cout << '0' <<  month << "/0" << day << '/' << (year%100) << endl;
			}
		}
	}
	//adds days of the previous months, then the day num then
	//uses the same 'year' thing from the Two-Digit format
	else if (format == 'J'){
		int julianNum = 0;
		for (int i = 0; i < month-1; i++){
			julianNum = julianNum + monthArr[i];
		}
		julianNum = julianNum + day;
		if(julianNum > 99){
			if (year > 9 && year < 100)
				cout << year << '-' << julianNum << endl;
			else if(year <= 9)
				cout << '0' << year << '-' << julianNum << endl;
			else if(year % 100 <= 9 && year % 100 > 0)
				cout << '0' << year % 100 << '-' << julianNum << endl;
			else if(year % 100 == 0)
				cout << "00-" << julianNum << endl;
			else
				cout << (year % 100) << '-' << julianNum << endl;
		}
		else if(julianNum < 100 && julianNum > 9){
			if(year > 9 && year < 100)
				cout << year << "-0" << julianNum << endl;
			else if(year <= 9)
				cout << '0' << year << "-0" << julianNum << endl;
			else if(year % 100 <= 9 && year % 100 > 0)
				cout << '0' << year % 100 << "-0" << julianNum << endl;
			else if (year % 100 == 0)
				cout << "00-0" << julianNum << endl;
			else
				cout << (year % 100) << "-0" << julianNum << endl;
		}
		else{
			if(year > 9 && year < 100)
				cout << year << "-00" << julianNum << endl;
			else if(year <=9)
				cout << '0' << year << "-00" << julianNum << endl;
			else if(year % 100 <= 9 && year % 100 > 0)
				cout << '0' << year % 100 << "-00" << julianNum << endl;
			else if(year % 100 == 0)
				cout << "00-00" << julianNum << endl;
			else
				cout << (year % 100) << "-00" << julianNum << endl;
		}
	}
//since the format char has to be a valid Format
//there's no need for another else if
	else{
		string abbrArr[12] = {"Jan", "Feb", "Mar", "Apr", "May", "June", "July", "Aug", "Sept", "Oct", "Nov", "Dec"};
		cout << abbrArr[month-1] << ' ' << day << ", " << year << endl;
	}
}

bool Date::Set(int m, int d, int y) {
//also checks to make sure it's a valid date
	int monthArr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
		monthArr[1] = 29;
	if(m > 12 || m < 1) {
		return false;
	} else if (d > monthArr[m-1] || d < 1) {
		return false;
	} else if (y < 0) {
		return false;
	} else {
		month = m;
		day = d;
		year = y;
		return true;
	}
}

int Date::GetMonth(){
	return month;
}

int Date::GetDay(){
	return day;
}

int Date::GetYear() {
	return year;
}
//afformentioned check format function
bool Date::SetFormat(char f) {
	if (f == 'D' || f == 'T' || f == 'L' || f == 'J'){
		format = f;
		return true;
	}
	return false;
}

//bunch of nested if statements that check if the date
//is the end of a month or year
void Date::Increment(int numDays){
	int monthArr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if ((year % 4 == 0 && year % 100 != 0) || year % 400)
		monthArr[1] = 29;
	if (day < (monthArr[month-1] - numDays))
		day = day + numDays;
	else {
		for (int i = 0; i < numDays; i++){
			if (day != monthArr[month-1]){
				day = day + 1;
			}
			else {
				if (month < 12){
					month = month + 1;
					day = 1;
				}
				else {
					year = year + 1;
					month = 1;
					day = 1;
				}
			}
		}
	}
}

int Date::Compare(const Date& d){
	if (year > d.year || month > d.month || day > d.day)
		return 1;
	if (d.year > year || d.month > month || d.day > day)
		return -1;
	return 0;
}
