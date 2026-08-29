class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {nums[i], i};
        }

        sort(arr.begin(), arr.end());

        int i = 0;
        int j = 0;
        vector<int> answer(n);

        while (i < n) {
            j = i + 1;
            while (j < n && arr[j].first - arr[j - 1].first <= limit) {
                ++j;
            }

            vector<int> indices(j - i);
            for (int k = i; k < j; ++k) {
                indices[k - i] = arr[k].second;
            }

            sort(indices.begin(), indices.end());

            for (int k = 0; k < indices.size(); ++k) {
                answer[indices[k]] = arr[i + k].first;
            }

            i = j;
        }

        return answer;
    }
};