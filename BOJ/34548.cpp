#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int find_parent(vector<int>& parent, int x){
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find_parent(parent, parent[x]);
}

void union_parent(vector<int>& parent, int x, int y){
    x = find_parent(parent, x);
    y = find_parent(parent, y);
    parent[y] = x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, t;
    cin >> n >> m >> t;

    vector<pair<int, pair<int, int>>> edges(m);
    for (auto& edge : edges) {
        cin >> edge.second.first >> edge.second.second >> edge.first;
    }

    sort(edges.begin(), edges.end());

    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    int components = n;
    int current = 1;
    ll answer = 0;

    for (const auto& edge : edges) {
        const int s = edge.first;
        const auto [u, v] = edge.second;

        if (s != current) {
            answer += 1ll * components * (s - current);
            current = s;
        }
        
        if (find_parent(parent, u) != find_parent(parent, v)) {
            --components;
            union_parent(parent, u, v);
        }
    }

    answer += 1ll * components * (t - current + 1);
    cout << answer << '\n';

    return 0;
}