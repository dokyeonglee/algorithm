#include <iostream>
#include <vector>

using namespace std;

bool can_color(const vector<vector<int>>& adj, vector<int>& node_colors, int current_node, int c) {
    node_colors[current_node] = c;
    for (auto& neighbor_node : adj[current_node]) {
        if (node_colors[neighbor_node] == -1) {
            if (!can_color(adj, node_colors, neighbor_node, c ^ 1)) {
                return false;
            }
        } else if(node_colors[neighbor_node] == c) {
            return false;
        }
    }

    return true;
}

bool is_bipartite(const vector<vector<int>>& adj) {
    vector<int> node_colors(adj.size(), -1);
    return can_color(adj, node_colors, 1, 0);
}

int min_colors(const vector<vector<int>>& adj) {
    if (is_bipartite(adj)) {
        return 2;
    }
    return 3;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    cout << min_colors(adj);

    return 0;

}