#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double a, b, c;
	cin >> a >> b >> c;
	double s = (a + b + c) / 2;
	cout << sqrt(s * (s - a) * (s - b) * (s - c));
}

