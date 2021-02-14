#include <iostream>

using namespace std;

int main()
{
	double weight, height;
	cout << "Weight (kg) : ";
	cin >> weight;
	cout << "Height (m) : ";
	cin >> height;
	cout << "BMI : " << weight / (height * height);
}

