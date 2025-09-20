#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

struct Solver {
    ll prefix_sum = 0;
    ll delta = 0;
    ll result = 0;

    ll solve(const int x) {
        delta += 2 * prefix_sum + x;
        prefix_sum += x;
        return result += delta;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    Solver solver;
    for (int i = 1; i <= n; ++i) {
        cout << solver.solve(arr[i]) << ' ';
    }

    return 0;
}