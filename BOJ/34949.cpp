#include <iostream>
#include <queue>

using namespace std;

vector<int> bfs(const vector<vector<int>>& adj) {
    const int n = adj.size() - 1;

    vector<int> distance(adj.size(), -1);
    distance[n] = 0;

    queue<int> q;
    q.push(n);

    while (!q.empty()) {
        const int now = q.front();
        q.pop();

        for (int next : adj[now]) {
            if (distance[next] == -1) {
                distance[next] = distance[now] + 1;
                q.push(next);
            }
        }
    }

    return distance;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;

        adj[x].push_back(i);
    }

    vector<int> distance = bfs(adj);
    for (int i = 1; i <= n; ++i) {
        cout << distance[i] << '\n';
    }

    return 0;
}