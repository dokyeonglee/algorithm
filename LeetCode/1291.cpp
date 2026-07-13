class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> sequential;

        for (int i = 1; i < 10; ++i) {
            sequential.push_back(i);
        }

        int idx = 0;
        while (idx < sequential.size()) {
            int d = sequential[idx] % 10;
            if (d < 9) {
                sequential.push_back(sequential[idx] * 10 + d + 1);
            }
            ++idx;
        }
  
        auto s = lower_bound(sequential.begin(), sequential.end(), low);
        auto e = upper_bound(sequential.begin(), sequential.end(), high);

        vector<int> answer(s, e);

        return answer;
    }
};