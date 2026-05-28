struct Trie {
    Trie* children[26];
    int min_length = INT_MAX;
    int idx = -1;

    Trie() {
        memset(children, 0, sizeof(children));
    }

    ~Trie() {
        for (int i = 0; i < 26; ++i) {
            if (children[i]) {
                delete children[i];
            }
        }
    }

    void insert(string& str, int word_idx) {
        Trie* now = this;

        if (now->min_length > str.size()) {
            now->idx = word_idx;
            now->min_length = str.size();
        }

        for (int i = str.size() - 1; i >= 0; --i) {
            int child_idx = str[i] - 'a';
            if (now->children[child_idx] == nullptr) {
                now->children[child_idx] = new Trie();
            }
            now = now->children[child_idx];
            if (now->min_length > str.size()) {
                now->idx = word_idx;
                now->min_length = str.size();
            }
        }    
    }

    int find(string& str) {
        Trie* now = this;
        int result = now->idx;
        for (int i = str.size() - 1; i >= 0; --i) {
            int child_idx = str[i] - 'a';
            if (now->children[child_idx] == nullptr) {
                return result;
            }
            now = now->children[child_idx];
            result = now->idx;
        }

        return result;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Trie* suffix_trie = new Trie();

        for (int i = 0; i < wordsContainer.size(); ++i) {
            suffix_trie->insert(wordsContainer[i], i);
        }

        vector<int> answer(wordsQuery.size());
        for (int i = 0; i < wordsQuery.size(); ++i) {
            answer[i] = suffix_trie->find(wordsQuery[i]);
        }

        delete suffix_trie;

        return answer;
    }
};