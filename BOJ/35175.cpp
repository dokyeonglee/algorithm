#include <iostream>

using namespace std;

int main() {
    long long n, a, b;
    cin >> n >> a >> b;

    n /= (n & -n);

    int check = 0;
    int cnt = 0;
    int x = n & 1;
    while (n > 0) {
        if (x == (n & 1)) {
            ++cnt;
        } else {
            if (cnt == 1) {
                check |= (1 << x);
            }
            x ^= 1;
            cnt = 1;
        }
        n >>= 1;
    }

    if (cnt == 1) {
        check = true;
    }

    if (a == b && x != 0b11) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}