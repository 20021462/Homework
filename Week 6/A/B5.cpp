#include<iostream>

using namespace std;

long F(int n) 
{
   if (n == 0) return 0;
   if (n == 1) return 1;
   return F(n-1) + F(n-2);
}

int main()
{
    int a; 
	cin >> a;
    cout << F(a) << endl; // de quy
    long fb = 0;
    long f0 = 0, f1 = 1;
    if(a == 0 || a == 1) {
        fb = a; cout << fb;
        return 0;
    }
    for(int i=2;i<=a;i++){
        fb = f0+f1;
        f0 = f1;
        f1 = fb;
    }
    cout << fb << endl; // vong lap
    return 0;
}

