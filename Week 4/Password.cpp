#include <iostream>

using namespace std;

string reverse(string word, int size) 
{
	string reverse = word;
	for (int i = 0; i < size; i++) {
		reverse[i] = word[size - i - 1];
	}
	return reverse;
}

int main()
{
	int n;
	cin >> n;
	
	string password[n];
	for (int i = 0; i < n; i++) {
		cin >> password[i];
	}
	
	int size = 0, position;
	for (int i = 0; i < n; i++) {
		if (password[i].size() % 2 == 0) continue;
		for (int j = i + 1; j < n; j++) {
			if (password[j].size() % 2 == 0) continue;
			string tmp = reverse(password[j], password[j].size());
			if (tmp == password[i]) {
				size = tmp.size();
				position = i;
				break;
			}	
		}
	}
	
	cout << size << ' ';
	size = (size - 1) / 2;
	char middle = password[position][6];
	cout << middle;	
	
	return 0;
}
