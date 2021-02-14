#include <iostream>

using namespace std;

int main()
{
	string Fibonacci = "b";
	string preFibonacci = "a";
	for (int i = 0; i < 10; i++) {
		string tmp = Fibonacci;
		Fibonacci += preFibonacci;
		preFibonacci = tmp;
		cout << Fibonacci << endl;
	}
}
