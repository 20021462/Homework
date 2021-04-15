#include <iostream>

using namespace std;

char* weird_string() {
    char c[] = { 1,2,3,4,5 };
    return c;
}

int main()
{
    int main(int argc, const char* argv[]) {
        cout << "Number of command-line arguments: " << argc << endl;
        for (int i = 0; i < argc; i++) {
            cout << "Argument #" << i << ": _" << argv[i] << "_\n";
        }
        return 0;
    }
}
