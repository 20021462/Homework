#include<iostream>
using namespace std;
int x1=10;
int x2=20;
int xx(int& );

int main(){
    cout << "x1->" << &x1 << endl;
    cout << xx(x1)<< endl;;
    cout << "x2->" << &x2 << endl;
    cout << xx(x2);
    return 0;
}

int xx(int &xxx){
    cout << "xxx->" << &xxx << endl;
    return xxx;
}
//a: cung 1 bien
//b: co
//c: co
