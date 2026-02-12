#include <iostream>
#include <vector>
#include <algorithm>

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

    while (1) {
        int n, m;
        cin >> n >> m;

        if (n == 0 && m == 0) {
            break;
        }

        vector<pair<int, pair<int, int>>> edges(m);
        for (auto& e : edges) {
            cin >> e.second.first >> e.second.second >> e.first;
        }

        sort(edges.begin(), edges.end());

        vector<int> parent(n);
        for (int i = 1; i < n; i++) {
            parent[i] = i;
        }

        int cnt = n;
        int answer = -1;
        for (auto& e : edges) {
            if (find_parent(parent, e.second.first) != find_parent(parent, e.second.second)) {
                --cnt;
                answer = max(answer, e.first);
                union_parent(parent, e.second.first, e.second.second);
            }
        }

        if (cnt == 1) {
            cout << answer << '\n';
        } else {
            cout << "IMPOSSIBLE\n";
        }

    }

    return 0;
}