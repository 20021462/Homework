#include <iostream>

using namespace std;

int main()
{
	int N = 0;
	while (N != -1) {
		cin >> N;
		if (N == -1) break;
		if (N >= 0 && N % 5 == 0) cout << N / 5 << endl;
		else cout << -1 << endl;
	}
	cout << "Bye";
}
