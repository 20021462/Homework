#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(time(0));
	int card1 = rand() % 101;
	int card2 = rand() % 101;
	int choice = rand() % 2 + 1;
	int choose, left;
	cout << "Bob chon xem the " << choice << " : ";
	if (choice == 1) {
		choose = card1;
		left = card2;
	}
	else {
		choose = card2;
		left = card1;
	}
	cout << choose << endl;
	if (choose >= 50) cout << "Bob quyet dinh chon the nay" << endl;
	else {
		cout << "Bob quyet dinh chon the con lai" << endl;
		int tmp = choose;
		choose = left;
		left = tmp;	
	}
	if (choose > left) cout << "Bob thang";
	else cout << "Alice thang";
	cout << endl << "The con lai la " << left;
	
}
