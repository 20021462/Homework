#include <iostream>

using namespace std;

string English(int n)
{
	string word;
	if (n >= 100) {
		switch (n / 100) {
			case 1 : 
				word += "one";
				n -= 100;
				break;
			case 2 : 
				word += "two";
				n -= 200;
				break;
			case 3 : 
				word += "three";
				n -= 300;
				break;
			case 4 : 
				word += "four";
				n -= 400;
				break;
			case 5 : 
				word += "five";
				n -= 500;
				break;
			case 6 : 
				word += "six";
				n -= 600;
				break;
			case 7 : 
				word += "seven";
				n -= 700;
				break;
			case 8 : 
				word += "eight";
				n -= 800;
				break;
			case 9 : 
				word += "nine";
				n -= 900;
				break;
		}
		word += " hundred";
	}
	if (n >= 10) {
		switch (n / 10) {
			case 1 : 
				switch (n -= 10) {
					case 0 : 
						word += " ten";
						break;
					case 1 : 
						word += " eleven";
						break;
					case 2 : 
						word += " twelve";
						break;
					case 3 : 
						word += " thirteen";
						break;
					case 4 : 
						word += " fourteen";
						break;
					case 5 : 
						word += " fifteen";
						break;
					case 6 : 
						word += " sixteen";
						break;
					case 7 : 
						word += " seventeen";
						break;
					case 8 : 
						word += " eighteen";
						break;
					case 9 : 
						word += " nineteen";
						break;
				}
				break;
			case 2 : 
				word += " twenty";
				n -= 20;
				break;
			case 3 : 
				word += " thirty";
				n -= 30;
				break;
			case 4 : 
				word += " forty";
				n -= 40;
				break;
			case 5 : 
				word += " fifty";
				n -= 50;
				break;
			case 6 : 
				word += " sixty";
				n -= 60;
				break;
			case 7 : 
				word += " seventy";
				n -= 70;
				break;
			case 8 : 
				word += " eighty";
				n -= 80;
				break;
			case 9 : 
				word += " ninety";
				n -= 90;
				break;
		}	
	}
	if (n <= 9) {
		switch (n) {
			case 1 : 
				word += " one";
				break;
			case 2 : 
				word += " two";
				break;
			case 3 : 
				word += " three";
				break;
			case 4 : 
				word += " four";
				break;
			case 5 : 
				word += " five";
				break;
			case 6 : 
				word += " six";
				break;
			case 7 : 
				word += " seven";
				break;
			case 8 : 
				word += " eight";
				break;
			case 9 : 
				word += " nine";
				break;
		}	
	}
	return word;
}

int main()
{
	long long n;
	cin >> n;
	string name;
	if (n < 0) {
		name += "negative ";
		n *= -1;		
	}
	if (n >= 1000000) {
		int tmp = n / 1000000;
		name += English(tmp);
		name += " million ";
		n -= tmp * 1000000;
	}
	if (n >= 1000) {
		int tmp = n / 1000;
		name += English(tmp);
		name += " thousand ";
		n -= tmp * 1000;
	}
	name += English(n);
	if (name[0] == ' ') name.erase(0,1);
	cout << name;
}
