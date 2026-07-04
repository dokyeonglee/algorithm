class Solution {
public:
    int find_parent(vector<int>& parent, int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find_parent(parent, parent[x]);
    }

    void union_parent(vector<int>& parent, int x, int y) {
        x = find_parent(parent, x);
        y = find_parent(parent, y);
        if (x != y) {
            parent[y] = x;
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }

        for (auto& r : roads) {
            union_parent(parent, r[0], r[1]);
        }

        int p = find_parent(parent, 1);
        int answer = INT_MAX;
        for (auto& r : roads) {
            if (find_parent(parent, r[0]) == p) {
                answer = min(answer, r[2]);
            }
        }

        return answer;
    }
};