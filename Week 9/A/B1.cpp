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
	cout << "(" << a.x << ", " << a.y << ")";
}
int main()
{
	point a(1, 2);
	printPoint(a);
	return 0;
}
