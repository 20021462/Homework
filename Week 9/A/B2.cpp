#include <iostream>

using namespace std;

struct point
{
	int x;
	int y;
	point(int x_, int y_)
	{
		this->x = x_;
		this->y = y_;
	}
};

void printPoint(point& a)
{
	cout << &a;
}

void printPoint2(point a)
{
	cout << &a;
}
int main()
{
	point a(1, 2);
	cout << &a << endl;
	printPoint(a);
	cout << endl;
	printPoint2(a);
	return 0;
}
