#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(const vector<vector<pair<int, int>>>& tree, vector<int>& distance, const int now, const int p) {
    for (auto [next, c] : tree[now]) {
        if (next != p) {
            distance[next] = distance[now] + c;
            dfs(tree, distance, next, now);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<pair<int, int>>> tree(10001);

    int u, v, c;
    while (cin >> u >> v >> c) {
        tree[u].emplace_back(v, c);
        tree[v].emplace_back(u, c);
    }

    vector<int> distance1(10001);
    vector<int> distance2(10001);

    dfs(tree, distance1, 1, -1);
    const int idx = max_element(distance1.begin() + 1, distance1.end()) - distance1.begin();
    dfs(tree, distance2, idx, -1);

    cout << *max_element(distance2.begin() + 1, distance2.end());

    return 0;
}