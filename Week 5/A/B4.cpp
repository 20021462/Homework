#include<iostream>

using namespace std;

void test(string x, int a[])
{
    cout << "string : " << &x << endl;
    cout << "array : " << &a[0] << endl;
}

int main(){
    string s="abc";
    int a[100];
    cout << "s : " << &s << endl;
    cout << "a[0] : " << &a[0] << endl;
    test(s, a);
    return 0;
}

//a:
//mang duoc truyen theo co che pass-by-reference

//b:
//string duoc truyen theo co che pass-by-value
