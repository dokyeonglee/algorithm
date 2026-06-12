class Solution {
private:
    static constexpr int MOD = 1e9 + 7;
public:
    long long mod_pow(long long a, long long n, int mod = MOD) {
        long long result = 1;
        while (n > 0) {
            if (n & 1) {
                result = result * a % mod;
            }
            a = a * a % mod;
            n >>= 1;
        }
        return result;
    }

    void dfs(vector<vector<int>>& tree, vector<vector<int>>& parent, vector<int>& depth, int now, int p) {
        parent[now][0] = p;

        for (int next : tree[now]) {
            if (next != p) {
                depth[next] = depth[now] + 1;
                dfs(tree, parent, depth, next, now);
            }
        }
    }

    int lca(vector<vector<int>>& parent, vector<int>& depth, int a, int b) {    
        if (depth[a] > depth[b]) {
            swap(a, b);
        }
    
        for (int i = 17; i >= 0; i--) {
            if (depth[a] <= depth[parent[b][i]]) {
                b = parent[b][i];
            }
        }

        if (a == b) {
            return a;
        }
    
        for (int i = 17; i >= 0; i--) {
            if (parent[a][i] != parent[b][i]) {
                a = parent[a][i];
                b = parent[b][i];
            }
        }
    
        return parent[a][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        vector<vector<int>> tree(n + 1);        

        for (auto& e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        vector<vector<int>> parent(tree.size(), vector<int>(18));
        vector<int> depth(tree.size());

        dfs(tree, parent, depth, 1, 0);

        for (int i = 1; i <= 17; ++i) {
            for (int j = 1; j < tree.size(); ++j) {
                parent[j][i] = parent[parent[j][i - 1]][i - 1];
            }
        }

        vector<int> answer(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            if (queries[i][0] != queries[i][1]) {
                int p = lca(parent, depth, queries[i][0], queries[i][1]);
                int l = depth[queries[i][0]] + depth[queries[i][1]] - 2 * depth[p];
                answer[i] = mod_pow(2, l - 1);
            }
        }

        return answer;
    }
};