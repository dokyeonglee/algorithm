#include <iostream>
#include <vector>

using namespace std;

const int UNCOLORED = -1;

bool is_bipartite(const vector<vector<int>>& adj, vector<int>& color, int now, int current_color) {

    color[now] = current_color;

    for (const int next : adj[now]) {
        if (color[next] == current_color) {
            return false;
        }
        if (color[next] == UNCOLORED) {
            int opposite_color = (current_color ^ 1);
            if (!is_bipartite(adj, color, next, opposite_color)) {
                return false;
            }
        }
    }

    return true;
}

int count_bipartite_colorings(const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> color(n, UNCOLORED);
    int bipartite_components = 0;

    for (int i = 0; i < n; ++i) {
        if (color[i] == UNCOLORED) {
            if (!is_bipartite(adj, color, i, 0)) {
                return -1;
            }
            ++bipartite_components;
        }
    }

    return (1 << bipartite_components);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> adj(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }

        cout << count_bipartite_colorings(adj) << '\n';
    }

    return 0;
}