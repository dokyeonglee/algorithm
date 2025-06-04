#include <iostream>
#include <vector>

using namespace std;

int calculate_depth(const vector<int>& parent, vector<int>& depth, int now) {
    auto& ret = depth[now];
    if (ret != -1) {
        return ret;
    }
    return ret = calculate_depth(parent, depth, parent[now]) + 1;
}

void set_depths(const vector<int>& parent, vector<int>& depth) {
    const int n = parent.size() - 1;
    depth[1] = 0;
    for (int i = 2; i <= n; ++i) {
        calculate_depth(parent, depth, i);
    }
}

int calculate_stoppable_nodes(const vector<int>& nodes_at_depth, const int depth) {
    const int n = nodes_at_depth.size();
    int stoppable_nodes = 0;
    for (int i = 0; i < n; i += depth) {
        stoppable_nodes += nodes_at_depth[i];
    }
    return stoppable_nodes;
}

int calculate_max_stoppable_nodes(const vector<int>& parent) {
    const int n = parent.size() - 1;

    vector<int> depth(n + 1, -1);
    set_depths(parent, depth);

    vector<int> nodes_at_depth(n);
    for (int i = 1; i <= n; ++i) {
        ++nodes_at_depth[depth[i]];
    }

    int max_stoppalbe_nodes = 1;

    for (int i = 2; i <= n - 1; ++i) {
        int stoppable_nodes = calculate_stoppable_nodes(nodes_at_depth, i);
        max_stoppalbe_nodes = max(max_stoppalbe_nodes, stoppable_nodes);
    }

    return max_stoppalbe_nodes;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> parent(n + 1);
    for (int i = 2; i <= n; ++i) {
        cin >> parent[i];
    }

    cout << calculate_max_stoppable_nodes(parent);  

    return 0;

}