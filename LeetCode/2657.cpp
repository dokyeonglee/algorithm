class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        long long bit_a = 0;
        long long bit_b = 0;
        vector<int> C(n);
        for (int i = 0; i < n; ++i) {
            bit_a |= (1ll << A[i]);
            bit_b |= (1ll << B[i]);
            C[i] = __builtin_popcountll(bit_a & bit_b);
        }
        return C;
    }
};