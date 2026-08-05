class Solution {
public:
    vector<bool> bfs(const vector<vector<int>>& adj, int src) {
        vector<bool> visited(adj.size());
        visited[src] = true;

        queue<int> q;
        q.emplace(src);

        while (!q.empty()) {
            int now = q.front();
            q.pop();

            for (int next : adj[now]) {
                if (!visited[next]) {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }

        return visited;
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (auto& e : invocations) {
            adj[e[0]].push_back(e[1]);
        }

        auto visited = bfs(adj, k);

        bool check = false;
        for (auto& e : invocations) {
            if (!visited[e[0]] && visited[e[1]]) {
                check = true;
                break;
            }
        }

        vector<int> answer;
        answer.reserve(n);

        if (check) {
            for (int i = 0; i < n; ++i) {
                answer.push_back(i);
            }
        } else {            
            for (int i = 0; i < n; ++i) {
                if (!visited[i]) {
                    answer.push_back(i);
                }
            }
        }

        return answer;
    }
};