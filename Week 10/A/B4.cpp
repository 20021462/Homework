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

int main()
{
	Point O(0, 0); 
	cout << &O << endl; // x co cung dia chi voi bien O 
	cout << &O.x << endl; // dia chi cua y ngay sau x
	cout << &O.y;
}
