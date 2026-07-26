class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xor1 = nums2.size() % 2 == 0 ? 0 : reduce(nums1.begin(), nums1.end(), 0, bit_xor<>());
        int xor2 = nums1.size() % 2 == 0 ? 0 : reduce(nums2.begin(), nums2.end(), 0, bit_xor<>());
        return xor1 ^ xor2;
    }
};