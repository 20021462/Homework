#include<iostream>

using namespace std;

int main(){
    int c = 3;
    int a[100];
    int d = 11;
    char b[100];
    for(int i=0;i<3;i++){
        cout << "a[" << i << "] : " << &a[i] << endl;
    }
    cout << "a[99] : " << &a[99] << endl;
	// dia chi cua cac bien cach nhau 4 byte , = voi kich thuoc cua int
    
	for(int i=0;i<3;i++){
        cout << "b[" << i << "] : " << (void*)&b[i] << endl;
    }
    cout << "b[99] : " << (void*)&b[99] << endl;
	// dia chi cua cac bien cach nhau 1 byte , = voi kich thuoc cua char
    
	cout << "c : " << &c << endl; 
    cout << "d : " << &d << endl; // cach dia chi cua a[99] 4 byte
    return 0;
}
