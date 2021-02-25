#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int tmp1 = n, tmp2;
	while (tmp1 > 0) {
		tmp2 = n - tmp1;
		for (int i = 0; i < tmp2; i++) cout << ' ';
		for (int i = 0; i < tmp1; i++) cout << '*';
		tmp1--;
		cout << endl;
	}
}
