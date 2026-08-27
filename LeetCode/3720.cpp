class Solution {
public:
    string solve(string& str, vector<int>& cnt, int idx) {
        for (int i = idx + 1; i < 26; ++i) {
            if (cnt[i]) {
                str += 'a' + i;
                --cnt[i];
                for (int j = 0; j < 26; ++j) {
                    str.append(cnt[j], 'a' + j);
                }
                return str;
            }
        }
        return "";
    }

    string lexGreaterPermutation(string s, string target) {
        vector<int> cnt(26);
        for (char ch : s) {
            ++cnt[ch - 'a'];
        }

        string prefix;
        for (int i = 0; i < s.size(); ++i) {
            int idx = target[i] - 'a';
            if (cnt[idx] == 0) {
                break;
            }
            --cnt[idx];
            prefix += target[i];
        }

        if (prefix.size() < s.size()) {
            string answer = solve(prefix, cnt, target[prefix.size()] - 'a');
            if (answer.size()) {
                return answer;
            }
        }

        for (int i = prefix.size() - 1; i >= 0; --i) {
            ++cnt[prefix[i] - 'a'];
            prefix.pop_back();
            string answer = solve(prefix, cnt, target[i] - 'a');
            if (answer.size()) {
                return answer;
            }
        }

        return "";
    }
};