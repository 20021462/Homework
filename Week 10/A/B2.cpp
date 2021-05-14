#include <iostream>

using namespace std;

struct Point
{
	private:
		int x;
		int y;
	
	public:
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

void pointer(Point a, Point &b)
{
	cout << &a << endl << &b << endl;
}

int main()
{
	Point O(0, 0);
	cout << &O << endl;
	pointer(O, O);
}
