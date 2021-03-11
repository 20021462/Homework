#include<iostream>

using namespace std;

void c1(int a)
{
    cout << "a1 : " << &a << endl;
}

int c2(int &a)
{
    cout << "a2 : " << &a << endl;
}

int main(){
    int x = 1;
    cout << "x : " << &x << endl;
    c1(x);
    c2(x);
    return 0;
}
// dia chi cua tham so khi truyen theo kieu pass-by-value khac voi dia chi cua doi so
// con dia chi cua tham so khi truyen theo kieu pass-by-reference giong voi dia chi cua doi so
