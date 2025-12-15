#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, s, t;
    cin >> n >> m >> s >> t;

    vector<vector<ll>> distance(n + 1, vector<ll>(n + 1, 1e9));
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        distance[u][v] = min(distance[u][v], (ll)c);
    }

    for (int i = 1; i <= n; ++i) {
        distance[i][i] = 0;
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int u1, v1, c1;
        int u2, v2, c2;

        cin >> u1 >> v1 >> c1;
        cin >> u2 >> v2 >> c2;

        ll answer = distance[s][t];

        answer = min(answer, distance[s][u1] + distance[v1][t] + c1);
        answer = min(answer, distance[s][u2] + distance[v2][t] + c2);
        answer = min(answer, distance[s][u1] + distance[v1][u2] + distance[v2][t] + c1 + c2);
        answer = min(answer, distance[s][u2] + distance[v2][u1] + distance[v1][t] + c1 + c2);
        if (answer == 1e9) {
            answer = -1;
        }

        cout << answer << '\n';
    }

    return 0;
}