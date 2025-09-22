#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int x;
        cin >> x;

        if (x == 0) {
            cout << 1 << '\n';
            cout << 2 << '\n';
        } else {
            const int a = 1 << (32 - __builtin_clz(x));
            cout << 2 << '\n';
            cout << a << ' ' << a + 1 << '\n';
        }
    }

    return 0;
}