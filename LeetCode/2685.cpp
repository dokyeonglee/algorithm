class Solution {
public:
    int find_parent(vector<int>& parent, int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find_parent(parent, parent[x]);
    }

    void union_parent(vector<int>& parent, vector<int>& sz, int x, int y) {
        x = find_parent(parent, x);
        y = find_parent(parent, y);
        if (x != y) {
            sz[x] += sz[y];
            parent[y] = x;
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        vector<int> sz(n, 1);

        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }

        for (auto& e : edges) {
            union_parent(parent, sz, e[0], e[1]);
        }

        vector<int> edge_counts(n);
        for (auto& e : edges) {
            ++edge_counts[find_parent(parent, e[0])];
        }

        int answer = 0;
        for (int i = 0; i < n; ++i) {
            if (find_parent(parent, i) == i) {
                int x = sz[i] * (sz[i] - 1) / 2;
                if (x == edge_counts[i]) {
                    ++answer;
                }
            }
        }

        return answer;
    }
};