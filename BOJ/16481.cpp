#include <iostream>

using namespace std;

int main() {
    double r1, r2, r3;
    cin >> r1 >> r2 >> r3;

    cout << fixed;
    cout.precision(10);
    cout << 1 / (1 / r1 + 1 / r2 + 1 / r3);

    return 0;
}