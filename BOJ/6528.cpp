#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed;
    cout.precision(6);

    while (1) {
        int n, m;
        cin >> n >> m;

        if (n == 0) {
            break;
        }

        vector<vector<double>> arr(n + 1, vector<double>(n + 1));
        for (int i = 0; i < m; ++i) {
            int u, v, p;
            cin >> u >> v >> p;
            arr[u][v] = p / 100.0;
            arr[v][u] = p / 100.0;
        }

        for (int i = 1; i <= n; ++i) {
            arr[i][i] = 1;
        }

        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    arr[i][j] = max(arr[i][j], arr[i][k] * arr[k][j]);
                }
            }
        }

        cout << arr[1][n] * 100 << " percent\n";
    }

    return 0;
}