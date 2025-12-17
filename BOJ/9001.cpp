#include <iostream>
#include <queue>

using namespace std;

void bfs(const vector<vector<int>>& adj, vector<bool>& visited, int src) {
    visited[src] = true;

    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        const int now = q.front();
        q.pop();

        for (const int next : adj[now]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

bool is_overlapped(const pair<pair<int, int>, pair<int, int>>& a, const pair<pair<int, int>, pair<int, int>>& b) {
    const int x1 = max(a.first.first, b.first.first);
    const int y1 = max(a.first.second, b.first.second);
    const int x2 = min(a.second.first, b.second.first);
    const int y2 = min(a.second.second, b.second.second);
    return x1 <= x2 && y1 <= y2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<pair<int, int>, pair<int, int>>> arr(n);
        for (auto& a : arr) {
            cin >> a.first.first >> a.first.second >> a.second.first >> a.second.second;
        }

        vector<vector<int>> adj(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (is_overlapped(arr[i], arr[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int answer = 0;

        vector<bool> visited(n);
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ++answer;
                bfs(adj, visited, i);
            }
        }

        cout << answer << '\n';
    }

    return 0;
}