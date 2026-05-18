class Solution {
public:
    int minJumps(vector<int>& arr) {
        map<int, vector<int>> indices;
        for (int i = 0; i < arr.size(); ++i) {
            indices[arr[i]].push_back(i);
        }

        vector<bool> visited(arr.size());
        visited[0] = true;

        queue<pair<int, int>> q;
        q.emplace(0, 0);

        while (!q.empty()) {
            auto [now, cnt] = q.front();
            q.pop();

            cout << now << ' ';

            if (now == arr.size() - 1) {
                return cnt;
            }

            if (arr[now] == arr.back()) {
                return cnt + 1;
            }

            if (now + 1 < arr.size() && !visited[now + 1]) {
                visited[now + 1] = true;
                q.emplace(now + 1, cnt + 1);
            }

            if (now - 1 >= 0 && !visited[now - 1]) {
                visited[now - 1] = true;
                q.emplace(now - 1, cnt + 1);
            }

            for (int next : indices[arr[now]]) {
                if (!visited[next]) {
                    visited[next] = true;
                    q.emplace(next, cnt + 1);
                }
            }

            indices[arr[now]].clear();
        }

        return -1;
    }
};