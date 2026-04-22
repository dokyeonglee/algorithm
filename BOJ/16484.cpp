#include <iostream>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    cout << fixed;
    cout.precision(1);
    cout << n / 2.0 - d;

    return 0;
}