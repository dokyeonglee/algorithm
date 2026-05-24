class Solution {
public:
    int solve(vector<int>& arr, vector<int>& dp, int idx, int d) {
        int& ret = dp[idx];
        if (ret != -1) {
            return ret;
        }

        ret = 1;

        int left = max(idx - d, 0);
        for (int i = idx - 1; i >= left && arr[idx] > arr[i]; --i) {
            ret = max(ret, solve(arr, dp, i, d) + 1);
        }

        int right = min(idx + d, (int)arr.size() - 1);
        for (int i = idx + 1; i <= right && arr[idx] > arr[i]; ++i) {
            ret = max(ret, solve(arr, dp, i, d) + 1);
        }

        return ret;
    }

    int maxJumps(vector<int>& arr, int d) {
        int jumps = 0;
        vector<int> dp(arr.size(), -1);
        for (int i = 0; i < dp.size(); ++i) {
            if (dp[i] == -1) {
                jumps = max(jumps, solve(arr, dp, i, d));
            }
        }

        return jumps;
    }
};