#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double f(const vector<pair<int, int>>& arr, double t) {
    double max_x = -1e18;
    double min_x = 1e18;
    for (auto [x, v] : arr) {
        max_x = max(max_x, x + t * v);
        min_x = min(min_x, x + t * v);
    }
    return max_x - min_x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed;
    cout.precision(2);

    while (1) {
        int n;
        cin >> n;

        if (n == 0) {
            break;
        }

        vector<pair<int, int>> arr(n);
        for (auto& [x, v] : arr) {
            cin >> x >> v;
        }

        double left = 0;
        double right = 1e5;
        while (left + 1e-9 < right) {
            double q1 = 0.51 * left + 0.49 * right;
            double q2 = 0.49 * left + 0.51 * right;
            if (f(arr, q1) > f(arr, q2)) {
                left = q1;
            } else {
                right = q2;
            }
        }

        cout << round(f(arr, left) * 100) / 100 << '\n';
    }

    return 0;
}