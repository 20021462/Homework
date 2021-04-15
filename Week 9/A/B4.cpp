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

int main()
{
	point a(1, 2);
	cout << &a << endl << &a.x << endl << &a.y;
	return 0;
}

//dia chi cua a la dia chi cua a.x 
//dia chi cua a.y la dia chi tiep theo cua a.x (trong truong hop nay la +4 do la kieu int)
