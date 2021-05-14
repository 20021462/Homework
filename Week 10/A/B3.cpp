#include <iostream>

using namespace std;

struct Point
{
	public:
		int x;
		int y;
		
		Point()
		{
		}
		
		Point(int x_, int y_)
		{
			x = x_;
			y = y_;
		}
		
		print()
		{
			cout <<	"(" << x << ", " << y << ")";
		}
};

Point mid_point(const Point& a, const Point& b)
{
	Point mid;
	mid.x = (a.x + b.x) / 2;
	mid.y = (a.y + b.y) / 2;
	return mid;
}

int main()
{
	Point O(0, 0);
	Point A(4, 6);
	Point B = mid_point(O, A);
	B.print();
}
