#include <iostream>

using namespace std;

int count_even(int a[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0) count++;
    }
    return count;
}

int main()
{
    int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
    cout << count_even(a, 5);
    cout << endl;
    cout << count_even(a + sizeof(a) / sizeof(int) - 5, 5);
    return 0;
}
