#include<iostream>

using namespace std;

void dequy(int a)
{
    int arr[1000];
    if(a==0) return;
    dequy(a-1);
}

int main(){
    int a; 
	cin >> a;
    dequy(a);
    return 0;
}
//a = 513 thì l?i
