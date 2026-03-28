#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    if (k == 0) {
        for (int i = 0; i < n; ++i) {
            cout << 0 << ' ';
        }
    } else if (n == 1 && k != 1) {
        cout << -1;
    } else {
        for (int i = 0; i < n; ++i) {
            if (i != k - 1) {
                cout << i << ' ';
            }
        }
        if (k != n + 1) {
            cout << 1000000000;
        }
    }

    return 0;
}