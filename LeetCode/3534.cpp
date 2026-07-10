class Solution {
public:
    int get_distance(const vector<vector<int>>& sparse_table, int u, int v) {
        if (u == v) {
            return 0;
        }
        if (u > v) {
            swap(u, v);
        }

        int now = u;
        int dist = 1;

        for (int i = 17; i >= 0; --i) {
            if (sparse_table[now][i] < v) {
                now = sparse_table[now][i];
                dist += 1 << i;
            }
        }

        if (sparse_table[now][0] < v) {
            dist = -1;
        }

        return dist;
    }
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>> nodes(n);
        for (int i = 0; i < n; i++) {
            nodes[i] = {nums[i], i};
        }

        sort(nodes.begin(), nodes.end());

        vector<vector<int>> sparse_table(n, vector<int>(18));
        int left = 0;
        for (int right = 0; right < n; ++right) {
            while (nodes[right].first - nodes[left].first > maxDiff) {
                sparse_table[left++][0] = right - 1;
            }
        }

        while (left < n) {
            sparse_table[left++][0] = n - 1;
        }

        for (int i = 1; i < 18; ++i) {
            for (int j = 0; j < n; ++j) {
                int p = sparse_table[j][i - 1];
                sparse_table[j][i] = sparse_table[p][i - 1];
            }
        }

        vector<int> foo(n);
        for (int i = 0; i < n; ++i) {
            foo[nodes[i].second] = i;
        }

        vector<int> answer(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            answer[i] = get_distance(sparse_table, foo[queries[i][0]], foo[queries[i][1]]);
        }

        return answer;
    }
};