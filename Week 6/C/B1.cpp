#include <iostream>
#include <math.h>

using namespace std;

bool check(int m, int value, int field[])
{
	if (m == 1) return true;
	for (int i = 1; i < m; i++) {
		if (field[i] == value || field[i] - value == i - m || field[i] - value == m - i) return false;
	}
	return true;
}

void print(int n, int field[])
{
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (field[j] == i) cout << "x "; 
			else cout << ". ";
		}
		cout << endl;
	}
	cout << endl;
}

void initialize(int n, int &m, int field[], int &count)
{
	for (int i = 1; i <= n; i++) {
		if (check(m, i, field) == 1) {
			field[m] = i;
			if (m == n) {
				print(n, field);
				count++;
			}
			else {
				m++;
				initialize(n, m, field, count);
				m--;
			}
		}
	}	
}

int main()
{
	int n;
	cin >> n ;
	int m = 1;
	int field[n];
	field[0] = 0;
	int count = 0;
	initialize(n, m, field, count);
	cout << count;
}
