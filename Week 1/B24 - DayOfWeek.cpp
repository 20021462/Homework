#include <iostream>

using namespace std;

bool checkLeapYear(int year)
{
	if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0) return true;
	else return false;		
}

bool checkDay(int day, int month, int year) 
{
	switch(month) {
		case 1 : case 3 : case 5 : case 7 : case 8 : case 10 : case 12 :
			if (day >= 1 && day <= 31) return true;
			else return false;
		case 4 : case 6 : case 9 : case 11 :
			if (day >= 1 && day <= 30) return true;
			else return false;
		case 2 :
			if (day == 29 && checkLeapYear(year) == 1) return true;
			else if (day >= 1 && day <= 28) return true;
			else return false;
		default :
			return false;
	}	
}

int main()
{
	int day, month, year;
	char tmp;
	cout << "Nhap ngay thang (d/m/yyyy) : ";
	cin >> day >> tmp >> month >> tmp >> year;
	if(!checkDay(day, month, year)) {
		cout << "Ngay khong hop le";
		return 0;
	}
	int JMD = (day + ((153 * (month + 12 * ((14 - month) / 12) - 3) + 2) / 5) +
    			(365 * (year + 4800 - ((14 - month) / 12))) +
    			((year + 4800 - ((14 - month) / 12)) / 4) - 
    			((year + 4800 - ((14 - month) / 12)) / 100) + 
    			((year + 4800 - ((14 - month) / 12)) / 400)  - 32045) % 7 + 2;
 	switch (JMD) {
 		case 8 : 
 			cout << "Sunday";
 			break;
 		case 2 : 
 			cout << "Monday";
 			break;	
 		case 3 : 
 			cout << "Tuesday";
 			break;
 		case 4 : 
 			cout << "Wednesday";
 			break;
 		case 5 : 
 			cout << "Thursday";
 			break;
 		case 6 : 
 			cout << "Friday";
 			break;
 		case 7 : 
 			cout << "Saturday";
 			break;
	 }
}
