class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int m = *max_element(nums.begin(), nums.end());
        vector<long long> cnt(m + 1);
        for (int num : nums) {
            ++cnt[num];
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 2 * i; j <= m; j += i) {
                cnt[i] += cnt[j];
            }
        }

        for (int i = 1; i <= m; ++i) {
            cnt[i] = cnt[i] * (cnt[i] - 1) / 2;
        }
 
        for (int i = m; i > 0; --i) {
            for (int j = 2 * i; j <= m; j += i) {
                cnt[i] -= cnt[j];
            }
        }
 
        for (int i = 1; i <= m; ++i) {
            cnt[i] += cnt[i - 1];
        }
 
        vector<int> answer(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            auto it = lower_bound(cnt.begin(), cnt.end(), queries[i] + 1) - cnt.begin();
            answer[i] = it;
        }
 
        return answer;
    }
};