#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Edge {
    int u;
    int v;
    int cost;

    bool operator<(const Edge& other) const {
        return cost < other.cost;
    }
};

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

pair<int, vector<pair<int, int>>> build_stable_network(
    const vector<pair<int, int>>& existing_edges,
    const vector<vector<int>>& cost
) {
    const int n = cost.size() - 1;

    vector<int> parent(n + 1);
    iota(parent.begin(), parent.end(), 0);

    for (const auto [u, v] : existing_edges) {
        union_parent(parent, u, v);
    }

    vector<Edge> edges;
    for (int i = 2; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            edges.push_back({i, j, cost[i][j]});
        }
    }

    sort(edges.begin(), edges.end());

    int total_cost = 0;
    vector<pair<int, int>> new_edges;
    for (auto& [u, v, cost] : edges) {
        if (find_parent(parent, u) != find_parent(parent, v)) {
            total_cost += cost;
            new_edges.emplace_back(u, v);
            union_parent(parent, u, v);
        }
    }

    return {total_cost, new_edges};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> existing_edges(m);
    for (auto& [u, v] : existing_edges) {
        cin >> u >> v;
    }

    vector<vector<int>> cost(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> cost[i][j];
        }
    }

    const auto& [total_cost, new_edges] = build_stable_network(existing_edges, cost);
    cout << total_cost << ' ' << new_edges.size() << '\n';
    for (const auto& [u, v] : new_edges) {
        cout << u << ' ' << v << '\n';
    }

    return 0;
}