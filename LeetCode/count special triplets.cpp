class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int mod = 1e9 + 7;
        vector<int> cnt(1e5 + 1);
        vector<int> cnt2(1e5 + 1);

        ++cnt[nums[0]];
        for (int i = 2; i < nums.size(); ++i) {
            ++cnt2[nums[i]];
        }

        long long answer = 0;        
        for (int i = 1; i < nums.size() - 1; ++i) {
            int target = 2 * nums[i];
            if (target < cnt.size() && cnt[target] && cnt2[target]) {
                answer += 1ll * cnt[target] * cnt2[target];
                answer %= mod;
            }
            ++cnt[nums[i]];
            --cnt2[nums[i + 1]];
        }
        answer %= mod;
        return answer;
    }
};