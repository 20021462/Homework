#include <iostream>
#include <math.h>

using namespace std;

void print(int n, int **matrix)
{
	for (int i = 0; i < pow(2,n); i++) {
		for (int j = 0; j < pow(2,n); j++) {
			if (matrix[i][j] == 0) cout << ". ";
			else cout << "o ";
		}
		cout << endl;
	}
}

int **Hadamard(int n)
{
	int N = pow(2,n);
	int **matrix = new int* [N];
	for (int i = 0; i < N; i++)
	{
		matrix[i] = new int[N];
	}
	if (n == 1) {
		matrix[0][0] = matrix[0][1] = matrix[1][0] = 0;
		matrix[1][1] = 1;
	}
	else 
	{
		N /= 2;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int **tmp = Hadamard(n-1);
				matrix[i][j] = matrix[i+N][j] = matrix[i][j+N] = tmp[i][j];
				if(tmp[i][j] == 0) matrix[i+N][j+N] = 1;
				else matrix[i+N][j+N] = 0;
			}
		}
	}
	return matrix;
	
}

int main()
{
	int n;
	cin >> n;
	print(n, Hadamard(n));
}
