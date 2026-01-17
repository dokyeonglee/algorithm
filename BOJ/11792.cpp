#include <iostream>
#include <vector>

using namespace std;

constexpr double PI = 3.14159265358979;
constexpr double HALF_PI = PI / 2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    cout << fixed;
    cout.precision(10);
    for (int i = 1; i <= t; ++i) {
        int r, v;
        cin >> r >> v;

        cout << "Case " << i << ": " << HALF_PI * r / v << '\n';
    }

    return 0;
}