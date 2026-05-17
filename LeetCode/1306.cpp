class Solution {
public:
    bool canReach(vector<int>& nums, int start) {
        vector<bool> visited(nums.size());

        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            int now = q.front();
            q.pop();

            if (now < 0 || now >= nums.size() || visited[now]) {
                continue;
            }

            if (nums[now] == 0) {
                return true;
            }

            visited[now] = true;
            q.push(now + nums[now]);
            q.push(now - nums[now]);
        }
        

        return false;
    }
};