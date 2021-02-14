#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	double arr[5];
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}
	double sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += arr[i];
	}
	sum /= 5;
	//cout << sum << endl;
	double tmp[5];
	double min;
	int vitri = 0;
	for (int i = 0; i < 5; i++) {
		tmp[i] = arr[i] - sum;
		if (tmp[i] < 0) tmp[i] *= -1;
		if (i == 0) min = tmp[i];
		//cout << tmp[i] << endl;
		if (min > tmp[i]) {
			min = tmp[i];
			vitri = i;	
		}
	}
	//cout << min << endl;
	cout << arr[vitri];
}
