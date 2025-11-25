#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    if (k < 2 * n) {
        cout << -1 << '\n';
    } else if (k == 2 * n) {
        cout << 2 * n - 1 << '\n';
    } else {
        cout << 2 * n << '\n';
    }

    return 0;
}