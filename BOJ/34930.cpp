#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int l, r;
        cin >> l >> r;

        int s = max(l, (r + 1) / 2);
        int sign = -1;

        cout << s << ' ';
        for (int i = r; i >= l; --i) {
            if (i == s) {
                continue;
            }
            cout << sign * i << ' ';
            sign = -sign;
        }
        cout << '\n';
    }

    return 0;
}