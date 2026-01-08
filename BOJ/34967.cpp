#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 2) {
        cout << 1 << ' ' <<  2 << '\n';
        return 0;
    }

    const int sz = (n - 2) / 2;

    if (n % 2) {
        cout << 1 << ' ';
    }
    cout << 32 * (n - 2) << ' ' << 16 * (n - 2) << ' ';
    cout << 8 * (n - 2) << ' ' << 4 * (n - 2) << ' ';
    for (int i = 2; i <= sz; ++i) {
        const int x = (n - i) * i;
        cout << x << ' ' << x - i << ' ';
    }

    return 0;
}