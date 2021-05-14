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

int main()
{
	Point A(3, 4);
	A.print();
}
