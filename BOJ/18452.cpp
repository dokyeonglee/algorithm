#include <iostream>
#include <vector>

using namespace std;

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

    int n, m;
    cin >> n >> m;

    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    vector<pair<int, int>> edges(m);
    for (auto& [u, v] : edges) {
        cin >> u >> v;
    }

    for (auto& [u, v] : edges) {
        if (find_parent(parent, u) != find_parent(parent, v)) {
            union_parent(parent, u, v);
        }
    }

    int answer = m - n;
    for (int i = 1; i <= n; ++i) {
        if (find_parent(parent, i) == i) {
            ++answer;
        }
    }

    cout << answer;

    return 0;
}