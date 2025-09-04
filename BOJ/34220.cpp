#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> added_edges_for_four_coloring(const vector<vector<int>>& tree) {
    const int n = tree.size() - 1;
    int leaf = -1;

    for (int i = 1; i <= n; ++i) {
        if (tree[i].size() >= 3) {
            return {
                {tree[i][0], tree[i][1]},
                {tree[i][0], tree[i][2]},
                {tree[i][1], tree[i][2]}
            };
        }
        if (tree[i].size() == 1) {
            leaf = i;
        }
    }

    int parent = tree[leaf][0];
    int grandparent = (tree[parent][0] == leaf ? tree[parent][1] : tree[parent][0]);
    int great_grandparent = (tree[grandparent][0] == parent ? tree[grandparent][1] : tree[grandparent][0]);

    return {
        {leaf, grandparent},
        {leaf, great_grandparent},
        {parent, great_grandparent}
    };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> tree(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    auto edges = added_edges_for_four_coloring(tree);

    cout << edges.size() << '\n';
    for (const auto [u, v] : edges) {
        cout << u << ' ' << v << '\n';
    }

    return 0;
}