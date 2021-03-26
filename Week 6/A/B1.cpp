#include <iostream>

using namespace std;

void check(int *array)
{
    cout << array << endl;
}

int main()
{
    int array[100];
        cout << array << endl;
        cout << &array[0] << endl;
        check(array);
    return 0;
}
// mang duoc truyen theo co che pass-by-reference

