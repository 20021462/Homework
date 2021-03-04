#include <iostream>

using namespace std;

int mysteryNumber(int arr[], int arr2[], int n) 
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= n; j++) {
			if(arr[i] == arr2[j]) {
				arr2[j] = -1;
				break;
			}
		}
	}
	
	for (int i = 0; i <= n; i++) {
		if (arr2[i] != -1) return arr2[i];
	}
}

int main()
{
	int n;
	cin >> n;
	
	int A[n], B[n + 1];
	for (int i = 0; i < n; i++) cin >> A[i];
	for (int i = 0; i <= n; i++) cin >> B[i];
	
	cout << mysteryNumber(A, B, n);
	
	return 0;
}
