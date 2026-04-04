#include <iostream>

using namespace std;

int problem_a(int x) {
    return (x + 2) / 3;
}

int problem_b(int x) {
    int result = 0;

    if (x == 1) {
        return 1;
    }

    while (x % 4 == 0) {
        ++result;
        x /= 4;
    }
    if (x % 2 == 0) {
        ++result;
        x /= 2;
    }

    for (int i = 3; i * i <= x; i += 2) {
        while (x % i == 0) {
            ++result;
            x /= i;
        }
    }

    if (x > 1) {
        ++result;
    }

    return result;
}

int main() {
    int m;
    cin >> m;

    cout << problem_a(m) << ' ' << problem_b(m);

    return 0;
}