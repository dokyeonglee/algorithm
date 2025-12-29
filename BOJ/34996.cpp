#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    cout << n * n + n - 1 << '\n';
    for (int i = 1; i <= n; ++i) {
        cout << i << ' ';
    }
    cout << 0 << ' ';
    for (int i = -n; i <= -1; ++i) {
        cout << i << ' ';
    }

    return 0;
}