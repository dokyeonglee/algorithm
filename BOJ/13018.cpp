#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    if (n == k) {
        cout << "Impossible\n";
    } else if (n - 1 == k) {
        for (int i = 1; i <= n; ++i) {
            cout << i << ' ';
        }
    } else {
        cout << n - k << ' ';
        for (int i = 1; i < n - k; ++i) {
            cout << i << ' ';
        }
        for (int i = n - k + 1; i <= n; ++i) {
            cout << i << ' ';
        }
    }

    return 0;
}