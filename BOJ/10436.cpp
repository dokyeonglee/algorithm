#include <iostream>
#include <vector>

using namespace std;

pair<int, int> solve(const int a, const int b) {
    if (b == 1) {
        return {1, a + 1};
    } else if (a < b) {
        return {b, b - a};
    }
    return {b, (a / b * 2 + 1) * b - a};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    char _;

    while (t--) {
        int x, a, b;
        cin >> x >> a >> _ >> b;

        const auto [p, q] = solve(a, b);
        cout << x << ' ' << p << '/' << q << '\n';
    }

    return 0;
}