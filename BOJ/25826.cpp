#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<ll>> arr(n + 2, vector<ll>(n + 2));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> arr[i][j];
        }
    }

    vector<vector<ll>> psum(n + 2, vector<ll>(n + 2));
    for (int i = 1; i < m; ++i) {
        int type, r1, c1, r2, c2, k;
        cin >> type >> r1 >> c1 >> r2 >> c2 >> k;
        ++r1;
        ++c1;
        ++r2;
        ++c2;
        psum[r1][c1] += k;
        psum[r1][c2 + 1] -= k;
        psum[r2 + 1][c1] -= k;
        psum[r2 + 1][c2 + 1] += k;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            psum[i][j] += psum[i][j - 1] + psum[i - 1][j] - psum[i - 1][j - 1];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            psum[i][j] += arr[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            psum[i][j] += psum[i][j - 1] + psum[i - 1][j] - psum[i - 1][j - 1];
        }
    }

    int type, r1, c1, r2, c2, k;
    cin >> type >> r1 >> c1 >> r2 >> c2 >> k;
    ++r1;
    ++c1;
    ++r2;
    ++c2;

    cout << psum[r2][c2] - psum[r2][c1 - 1] - psum[r1 - 1][c2] + psum[r1 - 1][c1 - 1];

    return 0;
}