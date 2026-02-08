#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (1) {
        int n;
        cin >> n;

        if (n == 0) {
            break;
        }

        vector<pair<double, double>> arr(n);
        for (auto& [x, y] : arr) {
            cin >> x >> y;
        }
        arr.push_back(arr[0]);

        double area = 0;
        for (int i = 0; i < n; ++i) {
            area += arr[i].first * arr[i + 1].second - arr[i].second * arr[i + 1].first;
        }
        area = abs(area) / 2;

        cout << round(area) << '\n';
    }

    return 0;
}