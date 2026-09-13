class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();

        vector<pair<int, int>> ones1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (img1[i][j]) {
                    ones1.emplace_back(i, j);
                }
            }
        }

        vector<pair<int, int>> ones2;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (img2[i][j]) {
                    ones2.emplace_back(i, j);
                }
            }
        }

        vector<vector<int>> cnt(2 * n, vector<int>(2 * n));
        for (auto& p1 : ones1) {
            for (auto& p2 : ones2) {
                int dr = p1.first - p2.first + n;
                int dc = p1.second - p2.second + n;
                ++cnt[dr][dc];
            }
        }

        int answer = 0;
        for (int i = 0; i < cnt.size(); ++i) {
            for (int j = 0; j < cnt[0].size(); ++j) {
                answer = max(answer, cnt[i][j]);
            }
        }

        return answer;
    }
};