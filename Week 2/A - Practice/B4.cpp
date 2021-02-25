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
	cout << "Nhap ngay thang (dd/mm/yyyy) : ";
	cin >> day >> tmp >> month >> tmp >> year;
	if(!checkDay(day, month, year)) {
		cout << "Ngay khong hop le";
		return 0;
	}
	
	int daygap[100];
	int n = 0;
	int tmp2 = -1;
	while (tmp2 != 0) {
		cin >> tmp2;
		daygap[n] = tmp2;
		n++;
	}
	
	for (int i = 0; i < n - 1; i++) {
		int day2 = day, month2 = month, year2 =year;
		
		if (daygap[i] > 0) {
			while (daygap[i] != 0) {
				daygap[i]--;
				day2++;
				if (checkDay(day2, month2, year2) == 0) {
					if (month2 < 12) {
						month2++;
						day2 = 1;
					} else {
						month2 = 1;
						day2 = 1;
						year2++;
					}
				}
			}			
		} else {
			while (daygap[i] != 0) {
				daygap[i]++;
				day2--;
				if (checkDay(day2, month2, year2) == 0) {
					if (month2 > 1) {
						month2--;
						day2 = 31;
						while (checkDay(day2, month2, year2) == 0) day2--;
					} else {
						month2 = 12;
						day2 = 31;
						year2--;
					}
				}
			}	
		}

		if (day2 < 10) cout << '0';
		cout << day2 << '/';
		if (month2 < 10) cout << '0'; 
		cout << month2 << '/' << year2 << endl;
	}
}
