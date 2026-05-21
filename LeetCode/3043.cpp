struct Trie {
    bool finish;
    Trie* next[10];

    Trie() : finish(false) {
        memset(next, 0, sizeof(next));
    }

    ~Trie() {
        for (int i = 0; i < 10; ++i) {
            if (next[i]) {
                delete next[i];
            }
        }
    }

    void insert(int key, int d) {
        if (d == 0) {
            finish = true;
        } else {
            int curr = key / d;
            if (next[curr] == NULL) {
                next[curr] = new Trie();
            }
            next[curr]->insert(key % d, d / 10);
        }
    }

    int common_prefix_length(int key, int d, int length) {
        if (d == 0) {
            return length;
        }
        int curr = key / d;
        if (next[curr] == NULL) {
            return length;
        }
        return next[curr]->common_prefix_length(key % d, d / 10, length + 1);
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie* root = new Trie();
        for (int i = 0; i < arr1.size(); ++i) {
            int d = 1;
            int temp = arr1[i];
            while (temp > 9) {
                d *= 10;
                temp /= 10;
            }
            root->insert(arr1[i], d);
        }

        int length = 0;
        for (int i = 0; i < arr2.size(); ++i) {
            int d = 1;
            int temp = arr2[i];
            while (temp > 9) {
                d *= 10;
                temp /= 10;
            }
            length = max(length, root->common_prefix_length(arr2[i], d, 0));
        }
        return length;       
    }
};