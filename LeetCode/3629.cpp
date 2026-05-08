const int MAX_NUM = 1e6;
const int MAX_FACTORS = 8;
vector<vector<int>> prime_factors(MAX_NUM + 1);

bool initailzied = []() {
    for (int i = 2; i <= MAX_NUM; ++i) {
        if (prime_factors[i].empty()) {
            for (int j = i; j <= MAX_NUM; j += i) {
                prime_factors[j].push_back(i);
            }
        }
    }
    return true;
}();

class Solution {
public:    
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;

        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < n; ++i) {
            for (int p : prime_factors[nums[i]]) {
                adj[p].push_back(i);
            }
        }

        vector<bool> visited(n);
        visited[0] = true;

        queue<int> q;
        q.push(0);

        while (true) {
            int sz = q.size();
            while (sz--) {
                int now = q.front();
                q.pop();

                if (now == n - 1) {
                    return jumps;
                }

                if (now > 0 && !visited[now - 1]) {
                    visited[now - 1] = true;
                    q.push(now - 1);
                }
                if (!visited[now + 1]) {
                    visited[now + 1] = true;
                    q.push(now + 1);
                }
                if (prime_factors[nums[now]].size() == 1 && adj.count(nums[now])) {
                    for (int next : adj[nums[now]]) {
                        if (!visited[next]) {
                            visited[next] = true;
                            q.push(next);
                        }
                    }
                    adj[nums[now]].clear();
                }
            }

            ++jumps;
        }

        return jumps;
    }
};