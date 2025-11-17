#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        const int k = n / 2;
        if (n % 2 == 0) {
            cout << k + 1 << " - " << k << " - " << 1 << '\n';
        } else {
            cout << k + 3 << " - " << k + 2 << " - " << 2 << '\n';
        }
    }

    return 0;
}