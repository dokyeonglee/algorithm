#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Edge {
    int u, v, cost;

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

bool can_build(vector<Edge>& edges, const int n, int p, int q) {
    sort(edges.begin(), edges.end());

    vector<int> parent(n + 1);
    iota(parent.begin(), parent.end(), 0);

    for (auto& edge : edges) {
        if (find_parent(parent, edge.u) != find_parent(parent, edge.v)) {
            union_parent(parent, edge.u, edge.v);
            if ((edge.u == p && edge.v == q) || (edge.u == q && edge.v == p)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m, p, q;
        cin >> n >> m >> p >> q;

        vector<Edge> edges(m);
        for (auto& edge : edges) {
            cin >> edge.u >> edge.v >> edge.cost;
        }

        if (can_build(edges, n, p, q)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}