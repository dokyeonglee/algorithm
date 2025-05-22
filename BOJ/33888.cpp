#include <iostream>
#include <queue>

using namespace std;

int find_head(const vector<vector<int>>& adj, const vector<bool>& visited) {
    for (int i = 1; i < adj.size(); i++) {
        if (!visited[i] and adj[i].size() == 3) {
            return i;
        }
    }
    return -1;
}

int find_tail(const vector<vector<int>>& adj) {
    for (int i = 1; i < adj.size(); i++) {
        if (adj[i].size() == 1) {
            return i;
        }
    }
    return -1;
}

vector<int> collect_core_nodes_from(const vector<vector<int>>& adj, vector<bool>& visited, int src) {

    vector<int> core_nodes;

    visited[src] = true;

    queue<int> q;
    q.emplace(src);

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (auto next : adj[now]) {
            if (!visited[next]) {
                visited[next] = true;
                if (adj[next].size() != 2) {
                    core_nodes.emplace_back(next);
                    continue;
                }
                q.emplace(next);
            }
        }
    }

    return core_nodes;
}

vector<int> find_core_nodes(const vector<vector<int>>& adj) {

    vector<bool> visited(adj.size());

    int tail = find_tail(adj);
    int bottom_wing = collect_core_nodes_from(adj, visited, tail)[0];

    vector<int> side_wings_and_center = collect_core_nodes_from(adj, visited, bottom_wing);

    int head = find_head(adj, visited);
    int center = -1;
    int left_wing = -1;
    int right_wing = -1;

    for (int& node : side_wings_and_center) {
        if(adj[node].size() == 4) {
            center = node;
        } else if(left_wing == -1) {
            left_wing = node;
        } else {
            right_wing = node;
        }
    }

    if (left_wing > right_wing) {
        swap(left_wing, right_wing);
    }

    return {head, left_wing, center, right_wing, bottom_wing, tail};
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    for (int i = -3; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    vector<int> core_nodes = find_core_nodes(adj);

    for (auto& node : core_nodes) {
        cout << node << ' ';
    }

    return 0;

}