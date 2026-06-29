class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int answer = 0;
        for (auto& pattern : patterns) {
            if (word.find(pattern) != string::npos) {
                ++answer;
            }
        }
        return answer;
    }
};