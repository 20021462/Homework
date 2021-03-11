#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <iomanip>
#include <windows.h> 

using namespace std;

void changeColor(int desiredColor);

void createField(int (*field)[100], int m, int n, int mine);

int mineCount(int (*field)[100], int m, int n, int x, int y);

void fillField(int (*field)[100], int m, int n);

void zeroSpread(int (*trueField)[100], int (*showField)[100], int m, int n, int x, int y, int &safePlace);

void printField(int (*field)[100], int m, int n);

void checkMine(int (*showField)[100], int (*trueField)[100], int m, int n, int safePlace);

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
		cin >> K; 
	}
	
	int field[100][100], trueField[100][100], showField[100][100];
	createField(field, m, n, K);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			showField[i][j] = -2;
			if (field[i][j] == -1) {
				trueField[i][j] = -1;
			}
		}
	}	
	fillField(trueField, m, n);
	for (int i = 0; i < 60; i++) cout << endl;
	printField(showField, m , n);
		
	int safePlace = m * n - K;
	checkMine(showField, trueField, m, n, safePlace);
}

void changeColor(int desiredColor){ 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor); 
} 

void createField(int (*field)[100], int m, int n, int mine) {
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

int mineCount(int (*field)[100], int m, int n, int x, int y) {
	int count = 0;
	for (int k = -1; k <= 1; k++) {
		if (x + k >= 0 && x + k < m) {
			for (int h = -1; h <= 1; h++) {
				if (y + h >= 0 && y + h < n && field[x+k][y+h] == -1) count++;		
			}	
		}
	}
	return count;
}

void fillField(int (*field)[100], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (field[i][j] != -1) field[i][j] = mineCount(field, m, n, i, j);
		}
	}
}

void zeroSpread(int (*trueField)[100], int (*showField)[100], int m, int n, int x, int y, int &safePlace) {
	for (int k = -1; k <= 1; k++) {
		if (x + k >= 0 && x + k < m) {
			for (int h = -1; h <= 1; h++) {
				if (y + h >= 0 && y + h < n && trueField[x+k][y+h] >= 0) {
					if (showField[x+k][y+h] == -2) safePlace--;
					if (trueField[x+k][y+h] == 0) {
						trueField[x+k][y+h] = -4;
						zeroSpread(trueField, showField, m, n, x+k, y+h, safePlace);
					}
					showField[x+k][y+h] = trueField[x+k][y+h];
				}		
			}	
		}
	}	
}

void printField(int (*field)[100], int m, int n) {
	cout << setw(4) << ' ';
	for (int i = 0; i < n; i++) {
		cout << setw(4) << i + 1;
	}
	cout << endl;
	for (int i = 0; i < m; i++) {
		cout << setw(4) << i + 1;
		for (int j = 0; j < n; j++) {
			if (field[i][j] == -2) cout << setw(4) << '-';
			else if (field[i][j] == -1) {
				changeColor(4);
				cout << setw(4) << 'x';
				changeColor(7);
			}
			else if (field[i][j] == -3) {
				changeColor(12);
				cout << setw(4) << 'o';
				changeColor(7);
			}			
			else if (field[i][j] == 0 || field[i][j] == -4) cout << setw(4) << ' ';		
			else if (field[i][j] > 0) {
				int color;
				switch (field[i][j]) {
					case 1 : case 5 :
						color = 1;
						break;
					case 2 : case 6 :
						color = 2;
						break;
					case 3 : case 7 :
						color = 6;
						break;
					case 4 : case 8 :
						color = 5;
						break;					
				}
				changeColor(color);
				cout << setw(4) << field[i][j];
				changeColor(7);
			}
		}
		cout << endl;
	}	
}

void checkMine(int (*showField)[100], int (*trueField)[100], int m, int n, int safePlace) {
	int alive = 1;
	while (alive == 1 && safePlace > 0) {
		cout << "Please type in the position (Column then row) : ";
		int x, y;
		cin >> y >> x;
		while (x > m || y > n) {
			cout << "Invalid input, please try again : ";
			cin >> x >> y;
		}
		x--; y--;
		cout << "If you want to put a flag here, type F, else type anything : ";
		char action;
		cin >> action;
		if (action == 'F' || action == 'f') {
			showField[x][y] = -3;
			for (int i = 0; i < 60; i++) cout << endl;
			printField(showField, m, n);
			continue;
		}	  				
		if (trueField[x][y] == -1) {
			for (int i = 0; i < 60; i++) cout << endl;
			changeColor(4);
			cout << "YOU ARE DEAD" << endl;
			changeColor(7);
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					if (trueField[i][j] == -1) {
						showField[i][j] = -1;
					}
				}
			}		
			printField(showField, m, n);
			break;			
		} else if (trueField[x][y] == 0) {
			zeroSpread(trueField, showField, m, n, x, y, safePlace);
			showField[x][y] = trueField[x][y];			
			for (int i = 0; i < 60; i++) cout << endl;
			printField(showField, m, n);						
		} else {
			showField[x][y] = trueField[x][y];
			safePlace--;
			for (int i = 0; i < 60; i++) cout << endl;
			printField(showField, m, n);			
		}		
	}
	if (safePlace == 0) {
		for (int i = 0; i < 60; i++) cout << endl;	
		changeColor(6);	
		cout << "YOU ARE WINNER !!" << endl;
		changeColor(7);
		printField(showField, m, n);					
	}
}
