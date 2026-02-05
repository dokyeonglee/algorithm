#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, price;
    cin >> n >> price;

    vector<vector<int>> arr(4);
    for (int i = 0; i < n; ++i) {
        int c, d;
        cin >> c >> d;
        arr[d].push_back(c);
    }

    for (int i = 1; i <= 3; ++i) {
        arr[i].push_back(0);
        sort(arr[i].begin(), arr[i].end());
    }

    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j < arr[i].size(); ++j) {
            arr[i][j] += arr[i][j - 1];
        }
    }

    vector<double> p = {1, 0.99, 0.98, 0.97};
    vector<vector<double>> prefix_mul(4);
    for (int i = 1; i <= 3; ++i) {
        prefix_mul[i].resize(arr[i].size());
        prefix_mul[i][0] = 1;
        for (int j = 1; j < prefix_mul[i].size(); ++j) {
            prefix_mul[i][j] = prefix_mul[i][j - 1] * p[i];
        }
    }

    double answer = 1e18;
    for (int i = 0; i < arr[1].size(); ++i) {
        for (int j = 0; j < arr[2].size(); ++j) {
            for (int k = 0; k < arr[3].size(); ++k) {
                answer = min(answer, price * prefix_mul[1][i] * prefix_mul[2][j] * prefix_mul[3][k] + arr[1][i] + arr[2][j] + arr[3][k]);
            }
        }
    }

    cout << fixed;
    cout.precision(15);
    cout << answer;

    return 0;
}