class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> answer(1 << n);
        for (int i = 0; i < answer.size(); ++i) {
            answer[i] = (i ^ (i >> 1));
        }
        return answer;
    }
};