#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int p = 1;
    int u = 2;
    int degree = k;

    for (int i = 1; i < n; ++i) {
        cout << p << ' ' << u++ << '\n';
        if (--degree == 0) {
            ++p;
            degree = k - 1;
        }
    }

    return 0;
}