#include <iostream>

using namespace std;

bool possible(const int n, const int k) {
    for (int i = 1; i * i <= k && i <= n; ++i) {
        if (k % i == 0 && i + k / i - 1 == n) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        if (possible(n, k)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}