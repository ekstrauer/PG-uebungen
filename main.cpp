#include <iostream>
using namespace std;

int main() {
    int a1 = 4;
    int a2 = 4;
    int b1 = 0;
    int b2 = 0;

    // Prä-Inkrement
    b1 = ++a1;
    cout << "Prä-Inkrement:" << endl;
    cout << "b1 = " << b1 << ", a1 = " << a1 << endl;

    // Post-Inkrement
    b2 = a2++;
    cout << "Post-Inkrement:" << endl;
    cout << "b2 = " << b2 << ", a2 = " << a2 << endl;

    return 0;
}
