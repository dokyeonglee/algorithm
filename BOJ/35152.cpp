#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int x = 1;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            x = i;
            break;
        }
    }

    cout << 2 + x + n / x << '\n';

    cout << "1 2\n";

    int u = 3;
    for (int i = 0; i < x; ++i) {
        cout << 1 << ' ' << u++ << '\n';
    }

    x = n / x;
    for (int i = 0; i < x; ++i) {
        cout << 2 << ' ' << u++ << '\n';
    }

    return 0;
}