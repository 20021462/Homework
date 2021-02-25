#include <iostream>

using namespace std;

int main()
{
	int n = 100;

	for (int i = 2; i <= n; i += 2) {
		cout << i << ' ';
	}
	cout << endl;

	int tmp = 2;
	while (tmp <= n) {
		cout << tmp << ' ';
		tmp += 2;
	}
	cout << endl;

	int tmp2 = 2;
	do {
		cout << tmp2 << ' ';
		tmp2 += 2;
	} while (tmp2 <= n);
}

