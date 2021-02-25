#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	n = 2 * n - 1;
	int tmp1 = 0, tmp2 = n;
	while (tmp2 > 0) {
		for (int i = 0; i < tmp1; i++) cout << ' ';
		for (int i = 0; i < tmp2; i++) cout << '*';
		for (int i = 0; i < tmp1; i++) cout << ' ';	
		tmp1++;
		tmp2 -= 2;
		cout << endl;
	}
}
