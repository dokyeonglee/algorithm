#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;

    if (n == 1) {
        cout << 0 << '\n';
    } else if (n % 2) {
        cout << n / 2 + 1 << '\n';
    } else {
        cout << n / 2 << '\n';
    }

    return 0;
}