class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> answer(nums.size());
        int left = 0;
        int right = nums.size() - 1;
        
        for (int i = 0, j = nums.size() - 1; i < nums.size(); ++i, --j) {
            if (nums[i] < pivot) {
                answer[left++] = nums[i];
            }
            if (nums[j] > pivot) {
                answer[right--] = nums[j];
            }
        }

        for (int i = left; i <= right; ++i) {
            answer[i] = pivot;
        }

        return answer;           
    }
};
