#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int test_case = 1; test_case <= t; ++test_case) {
        int n, k;
        cin >> n >> k;

        const int result = (n - k) >> (31 - __builtin_clz(k));
        cout << "Case #" << test_case << ": " << (result + 1) / 2 << ' ' << result / 2 << '\n';
    }

    return 0;
}