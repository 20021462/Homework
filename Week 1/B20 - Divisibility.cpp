#include <iostream>

using namespace std;

int main()
{
	int x, y;
	cin >> x >> y;
	bool check = (x % 7 == 0 && y % 7 == 0);
	cout << check;
}
