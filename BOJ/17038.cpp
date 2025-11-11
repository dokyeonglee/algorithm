#include <iostream>
#include <vector>
#include <queue>

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
    if (x != y) {
        parent[y] = x;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> parent(2 * n + 1);
    for (int i = 1; i < parent.size(); i++) {
        parent[i] = i;
    }

    for (int i = 0; i < m; ++i) {
        char c;
        int u, v;
        cin >> c >> u >> v;

        if (c == 'S') {
            union_parent(parent, u, v);
        } else {
            union_parent(parent, u, v + n);
            union_parent(parent, v, u + n);
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (find_parent(parent, i) == find_parent(parent, i + n)) {
            cout << 0;
            return 0;
        }
    }

    for (int i = 1; i <= n; ++i) {
        union_parent(parent, i, i + n);
    }

    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (find_parent(parent, i) == i) {
            ++cnt;
        }
    }

    cout << 1;
    for (int i = 0; i < cnt; ++i) {
        cout << 0;
    }

    return 0;
}