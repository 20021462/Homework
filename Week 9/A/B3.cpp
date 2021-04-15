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

point mid_point(const point& a, const point& b)
{
	point c((a.x + b.x) / 2, (a.y + b.y) / 2);
	return c;
}

void printPoint(point a)
{
	cout << "(" << a.x << ", " << a.y << ")";
}
int main()
{
	point a(1, 2);
	point b(1, 4);
	printPoint(mid_point(a, b));
	return 0;
}
