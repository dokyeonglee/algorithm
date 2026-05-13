class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> move_count(2 * limit + 2);

        move_count[2] = n;
        for (int i = 0; i < n / 2; ++i) {
            int a = min(nums[i], nums[n - 1 - i]);
            int b = (nums[i] ^ nums[n - 1 - i] ^ a);

            move_count[a + 1] -= 1;
            move_count[a + b] -= 1;
            move_count[a + b + 1] += 1;
            move_count[b + limit + 1] += 1;
        }

        for (int i = 2; i < move_count.size(); ++i) {
            move_count[i] += move_count[i - 1];
        }
        
        return *min_element(move_count.begin() + 2, move_count.end() - 1);
    }
};