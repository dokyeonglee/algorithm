class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int max_num = INT_MIN;
        int min_num = INT_MAX;
        for (int num : nums) {
            max_num = max(max_num, num);
            min_num = min(min_num, num);
        }
        return 1ll * k * (max_num - min_num);        
    }
};