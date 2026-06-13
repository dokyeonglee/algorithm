class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string answer;
        for (auto& word : words) {
            int sum = 0;
            for (char c : word) {
                sum += weights[c - 'a'];
            }
            answer += 'z' - sum % 26;
        }
        return answer;
    }
};