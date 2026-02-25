#include <iostream>

using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;

    if (n <= k) {
        cout << 2 * n - 1;
    } else {
        cout << (n * n - k * k + k  - 1) / k + 2 * k - 1;
    }

    return 0;
}