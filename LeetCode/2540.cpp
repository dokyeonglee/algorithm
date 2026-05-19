class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int j = 0;
        for (int i = 0; i < nums1.size(); ++i) {
            while (j < nums2.size() && nums2[j] < nums1[i]) {
                ++j;
            }
            if (j == nums2.size()) {
                break;
            }
            if (nums1[i] == nums2[j]) {
                return nums1[i];
            }

        }
        return -1;    
    }
};