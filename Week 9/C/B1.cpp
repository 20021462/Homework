#include<iostream>

using namespace std;

struct String
{
	int n = 0;
	char* str;
	String(const char* chr)
	{
		while (chr[n] != NULL)
		{
			n++;
		}
		str = new char[n];

		for (int i = 0; i < n; i++)
		{
			str[i] = chr[i];
		}
	}
	~String()
	{
		delete str;
		str = NULL;
	}
	void print()
	{
		for (int i = 0; i < n; i++)
		{
			cout << str[i];
		}
		cout << endl;
	}

	void append(const char* chr)
	{
		int x = 0;
		while (chr[x] != NULL)
		{
			x++;
		}
		char* temp = new char[x + n];
		for (int i = 0; i < n; i++)
		{
			temp[i] = str[i];
		}
		for (int i = 0; i < x; i++)
		{
			temp[n + i] = chr[i];
		}
		n += x;
		str = temp;

	}
};

int main()
{
	String s("Hello");
	s.print();
	s.append(" world");
	s.print();
	return 0;
}
