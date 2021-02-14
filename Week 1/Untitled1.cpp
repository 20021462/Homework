#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Map {

private:
	double width;
	double height;
	char* length;

public:
	//Constructor
	Map(int wid, int hei) {

		width = wid;
		height = hei;
		length = new char[width * height];

		for (int i = 0; i < width * height; i++) {
			length[i] = '#';
		}
	}

	void print() {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {

				srand(time(NULL));
				char symbol[2] = { '.', '#' };
				char random = symbol[rand() % 2];

				if (i == 0 || i == height - 1 ||
					j == 0 || j == width - 1) {
					cout << length[j];
				}

				else {
					cout << random;
				}
			}
			cout << endl;
		}
	}

	//Destructor
	~Map() {
		delete[] length;
	}
};

int main() {

	int width;
	int height;
	cout << "Enter the width: ";
	cin >> width;

	cout << "Enter the height: ";
	cin >> height;

	Map Map(width, height);
	Map.print();

	return 0;
}



