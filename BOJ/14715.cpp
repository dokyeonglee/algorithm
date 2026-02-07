#include <iostream>

using namespace std;

int main() {
    int k;
    cin >> k;

    int cnt = 0;
    for (int i = 2; i * i <= k; ++i) {
        while (k % i == 0) {
            k /= i;
            ++cnt;
        }
    }

    if (k > 1) {
        ++cnt;
    }

    cout << 31 - __builtin_clz(2 * cnt - 1) << '\n';

    return 0;
}