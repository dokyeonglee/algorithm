class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xor_sum = 0;
        for (int d : derived) {
            xor_sum ^= d;
        }
        return xor_sum == 0;
    }
};