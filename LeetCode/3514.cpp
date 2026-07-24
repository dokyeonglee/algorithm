class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        bool check[2048] = {};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                check[nums[i] ^ nums[j]] = true;
            }
        }

        bool check2[2048] = {};
        for (int i = 0; i < 2048; ++i) {
            if (check[i]) {
                for (int num : nums) {
                    check2[i ^ num] = true;
                }
            }
        }

        int answer = 0;
        for (int i = 0; i < 2048; ++i) {
            answer += check2[i];
        }

        return answer;
    }
};