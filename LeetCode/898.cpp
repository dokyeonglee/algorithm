class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> answer;
        unordered_set<int> now;
        now.insert(0);
        for (int a : arr) {
            unordered_set<int> temp;
            temp.insert(a);
            for (int x : now) {
                temp.insert(a | x);
            }
            now = temp;
            answer.insert(now.begin(), now.end());
        }

        return answer.size();
    }
};