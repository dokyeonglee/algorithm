#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << 2;
        return 0;
    }

    if (n == 2) {
        cout << 2 << ' ' << 4;
        return 0;
    }

    cout << n - 1 + n % 2 << ' ';
    for (int i = 1; i < n; ++i) {
        cout << 2 * i << ' ';
    }

    return 0;
}