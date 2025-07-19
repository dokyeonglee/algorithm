#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
using ll = long long;

constexpr int MOD = 1000000007;

struct Edge {
    int u;
    int v;
    int capacity;
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

bool should_cut(vector<int>& parent, int u, int v, const int src, const int dst) {
    u = find_parent(parent, u);
    v = find_parent(parent, v);
    int parent_src = find_parent(parent, src);
    int parent_dst = find_parent(parent, dst);

    return (u == parent_src && v == parent_dst) || (u == parent_dst && v == parent_src);
}

int calculate_min_cut(const vector<Edge>& edges, const int n) {
    const int src = 0;
    const int dst = n - 1;

    vector<int> parent(n + 1);
    iota(parent.begin(), parent.end(), 0);

    int min_cut = 0;

    for (int i = edges.size() - 1; i >= 0; --i) {
        const auto& edge = edges[i];

        if (should_cut(parent, edge.u, edge.v, src, dst)) {
            min_cut += edge.capacity;
            min_cut %= MOD;
        } else {
            union_parent(parent, edge.u, edge.v);
        }
    }

    return min_cut;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    ll p = 1;

    for (auto& edge : edges) {
        cin >> edge.u >> edge.v;
        edge.capacity = p;
        p = p * 3 % MOD;
    }

    cout << calculate_min_cut(edges, n) << '\n';

    return 0;
}