#include <iostream>

using namespace std;

bool has_solution(const int n) {
    return n == 1 || ((n + 2) & (n + 1)) == 0;
}

int main() {
    int n;
    cin >> n;

    if (!has_solution(n)) {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 1; i <= n; ++i) {
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}