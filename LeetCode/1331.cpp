class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> s(arr.begin(), arr.end());

        sort(s.begin(), s.end());
        s.erase(unique(s.begin(), s.end()), s.end());

        vector<int> answer(arr.size());
        for (int i = 0; i < arr.size(); ++i) {
            answer[i] = lower_bound(s.begin(), s.end(), arr[i]) - s.begin() + 1;
        }

        return answer;
    }
};