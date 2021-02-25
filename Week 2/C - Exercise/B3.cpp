#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int tmp1 = n - 1, tmp2 = 1;
	n = 2 * n - 1;
	while (tmp2 <= n) {
		for (int i = 0; i < tmp1; i++) cout << ' ';
		for (int i = 0; i < tmp2; i++) cout << '*';
		for (int i = 0; i < tmp1; i++) cout << ' ';	
		tmp1--;
		tmp2 += 2;
		cout << endl;
	}
}
