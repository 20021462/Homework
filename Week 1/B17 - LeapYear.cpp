#include <iostream>

using namespace std;

int main()
{
	int LeapYear;
	cin >> LeapYear;
	if (LeapYear % 400 == 0 || LeapYear % 4 == 0 && LeapYear % 100 != 0) {
		cout << "true";
	} else cout << "false";
	
}
