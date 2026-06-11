class Solution {
private:
    static constexpr int MOD = 1e9 + 7;
public:
    long long mod_pow(long long a, long long n, int mod = MOD) {
        long long result = 1;
        while (n) {
            if (n & 1) {
                result = result * a % mod;
            }
            a = a * a % mod;
            n >>= 1;
        }
        return result;
    }

    void dfs(vector<int> tree[], vector<int>& depth, int now, int p) {
        for (int next : tree[now]) {
            if (next != p) {
                depth[next] = depth[now] + 1;
                dfs(tree, depth, next, now);
            }
        }
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> depth(n + 1);
        vector<int> tree[n + 1];
        for (auto& e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        dfs(tree, depth, 1, -1);

        int max_depth = *max_element(depth.begin(), depth.end());

        return mod_pow(2, max_depth - 1);
    }
};