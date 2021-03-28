#include <iostream>

using namespace std;

void partition(int max, int n, int &sum, int result[], int &length)
{
	for (int i = n; i >= 1; i--) {
		if (i + sum == max) 
		{
			result[length] = i;
			for (int j = 0; j <= length; j++) cout << result[j] << ' ';
			cout << endl;
		} 
		else if (i + sum < max)
		{
			result[length] = i;
			length++;
			sum += i;
			partition(max, i, sum, result, length);
			sum -= i;
			length--;
			//i--;	
		}
	}
}

int main()
{
	int n;
	cin >> n;
	int result[n];
	int sum = 0, length = 0;
	partition(n, n, sum, result, length);
}
