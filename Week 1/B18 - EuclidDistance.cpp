#include <iostream>
#include <math.h>

using namespace std;

struct point2d
{
	double x, y;

	void input() {
		cin >> x >> y;
	}
};

int main()
{
	point2d A, B;
	A.input();
	B.input();
	double x = A.x - B.x;
	double y = A.y - B.y;
	cout << sqrt(x*x + y*y); 
}
