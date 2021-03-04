#include <iostream>

using namespace std;

bool SherlockAnswer(int arr[], int size) 
{
	int leftSum = 0, rightSum = 0;
	for (int i = 0; i < size; i++) {
		rightSum += arr[i];
	}
	
	for (int i = 0; i < size; i++) {
		rightSum -= arr[i];
		if (i != 0) leftSum += arr[i - 1];
		if (rightSum == leftSum) return true; 
	}
	
	return false;
}

int main()
{
	int test;
	cin >> test;
	int answer[test];
	
	for (int i = 0; i < test; i++) {
		int n;
		cin >> n;
		int question[n];
		for(int j = 0; j < n; j++) {
			cin >> question[j];
		}
		
		answer[i] = SherlockAnswer(question, n);
	}
	
	for (int i = 0; i < test; i++) {
		if (answer[i] == 1) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
