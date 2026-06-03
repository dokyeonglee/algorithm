class Solution {
public:
    char toggle = ('0' ^ '1');
    string findDifferentBinaryString(vector<string>& nums) {
        string cantor;
        for (int i = 0; i < nums.size(); ++i) {
            cantor += (nums[i][i] ^ toggle);
        }
        return cantor;
    }
};