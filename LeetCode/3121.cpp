class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> check(26);
        for (char c : word) {
            if (c >= 'A' && c <= 'Z') {
                check[c - 'A'] |= 1;
            } else if (c >= 'a' && c <= 'z') {
                int idx = c - 'a';
                if (check[idx] & 1) {
                    check[idx] = -1;
                } else {
                    check[idx] |= 2;
                }
            }
        }

        int answer = 0;
        for (int i = 0; i < 26; ++i) {
            if (check[i] == 3) {
                ++answer;
            }
        }
        
        return answer;
    }
};