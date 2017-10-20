//NAME: Brandon Hahn
//SECTION: 4

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Date
{
public:
	Date();
	Date(int m, int d, int y);
	void Input();
	void Show();
	bool Set(int m, int d, int y);
	int GetMonth();
	int GetDay();
	int GetYear();
	bool SetFormat(char f);
	void Increment(int numDays = 1);
	int Compare(const Date& d);

private:
	int month, day, year;
	char format;

};

