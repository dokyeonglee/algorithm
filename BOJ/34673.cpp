#include <iostream>
#include <vector>
#include <map>

using namespace std;
using ll = long long;

void dfs(const vector<vector<pair<int, int>>>& adj, vector<ll>& distance, const int now, const int p) {
    for (const auto [next, c] : adj[now]) {
        if (next != p) {
            distance[next] = distance[now] + c;
            dfs(adj, distance, next, now);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v, c;
        cin >> u >> v >> c;

        adj[u].emplace_back(v, c);
        adj[v].emplace_back(u, c);
    }

    vector<int> populations(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> populations[i];
    }

    vector<ll> distance(n + 1);
    dfs(adj, distance, 1, -1);

    map<pair<int, ll>, int> mp;
    for (int i = 1; i <= n; ++i) {
        ++mp[{populations[i], distance[i]}];
    }

    ll undefined = 0;
    for (const auto& it : mp) {
        undefined += 1ll * it.second * (it.second - 1);
    }

    const ll up = (1ll * n * (n - 1) - undefined) / 2;
    const ll down = up;

    cout << up << ' ' << down << '\n';

    return 0;
}