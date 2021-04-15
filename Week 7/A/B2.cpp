#include<iostream>

using namespace std;

void size(int a[])
{
    cout << sizeof(a);
}

int main()
{
    int a[10];
    cout << sizeof(a) << endl;
    size(a);
    return 0;
}
