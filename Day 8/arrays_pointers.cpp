#include <iostream>
using namespace std;

int main() {
    int a[10];
    cout << *a << endl;
    cout << &a[0] << endl;

    a[0] = 5;
    a[1] = 10;

    cout << *a << endl; // 5
    cout << *(a + 1) << endl; // 10

    int *p = &a[0];

    cout << a << endl;
    cout << p << endl;

    cout << &p << endl;
    cout << &a << endl;

    cout << sizeof(p) << endl; // 8
    cout << sizeof(a) << endl; // 40

    p = p + 1;  // valid
    // a = a + 1; (Not Valid)
    // a++;       (Not Valid)
}