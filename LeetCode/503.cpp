class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> answer(nums.size(), -1);
        stack<int> s;
        for (int i = 2 * nums.size() - 1; i >= 0; --i) {
            while (!s.empty() && s.top() <= nums[i % nums.size()]) {
                s.pop();
            }
            if (!s.empty()) {
                answer[i % nums.size()] = s.top();
            }
            s.push(nums[i % nums.size()]);
        }

        return answer;    
    }
};