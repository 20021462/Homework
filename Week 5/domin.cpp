#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void createField(int (*field)[100], int m, int n, int mine);

void printField(int (*field)[100], int m, int n);

void printMine(int (*field)[100], int m, int n);

void checkMine(int (*field)[100], int m, int n, int safePlace);

int main()
{
	cout << "WELCOME TO PROTO MINESWEEPER !" << endl;
	cout << "Size of field : ";
	int m, n;
	cin >> m >> n;
	while (m <= 0 || n <= 0) {
		cout << "Invalid input, please fill in again : ";
		cin >> m; 
	}
	cout << "Mine : ";
	int K;
	cin >> K;
	while (K <= 0 || K > m * n) {
		cout << "Invalid input, please fill in again : ";
		cin >> m; 
	}
	
	int field[100][100];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			field[i][j] = 0;
		}
	}
	
	createField(field, m, n, K);
	for (int i = 0; i < 60; i++) cout << endl;
	printField(field, m , n);
	
	int safePlace = m * n - K;
	
	checkMine(field, m, n, safePlace);
}

void createField(int (*field)[100], int m, int n, int mine)
{
	srand(time(0));
	while (mine > 0) {
		int tmp1, tmp2;
		tmp1 = rand() % m;
		tmp2 = rand() % n;
		if (field[tmp1][tmp2] != -1) {
			field[tmp1][tmp2] = -1;
			mine--;	
		}
	}	
}

void printField(int (*field)[100], int m, int n)
{
	cout << setw(4) << ' ';
	for (int i = 0; i < n; i++) {
		cout << setw(4) << i + 1;
	}
	cout << endl;
	for (int i = 0; i < m; i++) {
		cout << setw(4) << i + 1;
		for (int j = 0; j < n; j++) {
			if (field[i][j] == -1) cout << setw(4) << '-';
			else if (field[i][j] == 0) cout << setw(4) << '-';
			else if (field[i][j] == 1) cout << setw(4) << 'o';
		}
		cout << endl;
	}	
}

void printMine(int (*field)[100], int m, int n)
{
	cout << setw(4) << ' ';
	for (int i = 0; i < n; i++) {
		cout << setw(4) << i + 1;
	}
	cout << endl;
	for (int i = 0; i < m; i++) {
		cout << setw(4) << i + 1;
		for (int j = 0; j < n; j++) {
			if (field[i][j] == -1) cout << setw(4) << 'x';
			else if (field[i][j] == 0) cout << setw(4) << '-';
			else if (field[i][j] == 1) cout << setw(4) << 'o';
		}
		cout << endl;
	}	
}

void checkMine(int (*field)[100], int m, int n, int safePlace)
{
	int alive = 1;
	while (alive == 1 && safePlace > 0) {
		cout << "Please type in the position you want to dig : ";
		int x, y;
		cin >> x >> y;
		while (x > m || y > n) {
			cout << "Invalid input, please try again : ";
			cin >> x >> y;
		}
		x--; y--;
		if (field[x][y] == 0) {
			field[x][y] = 1;
			for (int i = 0; i < 60; i++) cout << endl;				
			cout << "That's a safe place" << endl; 
			printField(field, m, n);		
		}
		else if (field[x][y] == 1) {
			cout << "You have already dig here" << endl;
			continue;
		} else if (field[x][y] == -1) {
			for (int i = 0; i < 60; i++) cout << endl;			
			cout << "YOU ARE DEAD !" << endl;
			alive = 0;
			printMine(field, m, n);
		}		
	}
	if (safePlace == 0) cout << "YOU ARE WINNER !!";
}
