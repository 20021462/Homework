#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int matrix[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i + j <= n - 1) matrix[i][j] = i + j + 1;
			else matrix[i][j] = i + j - n + 1;
			cout << setw(4) << matrix[i][j];  
		}
		cout << endl;
	}
}
