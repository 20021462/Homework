#include<iostream>

using namespace std;

long long factorial(int x)
{
    cout << "x = " << x << " at " << &x << endl;
    if(x==1) return 1;
    return factorial(x-1)*(long long)x;
}

int main()
{
	int x;
	cin >> x;
    cout << factorial(x);
    return 0;
}

