class Solution {
public:
    const int MOD = 1e9 + 7;

    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        if (n == m) {
            return 1ll * (n - 1) * (m - 1) % MOD;
        }

        if (hFences.size() < vFences.size()) {
            swap(n, m);
            swap(hFences, vFences);
        }

        vFences.push_back(1);
        vFences.push_back(n);

        sort(vFences.begin(), vFences.end());

        vector<int> widths;
        widths.reserve(vFences.size() * (vFences.size() - 1) / 2);
        for (int i = 0; i < vFences.size(); ++i) {
            for (int j = i + 1; j < vFences.size(); ++j) {
                widths.push_back(vFences[j] - vFences[i]);
            }
        }

        sort(widths.begin(), widths.end());

        int length = -1;
        if (binary_search(widths.begin(), widths.end(), m - 1)) {
            length = m - 1;
        } else {
            hFences.push_back(1);
            hFences.push_back(m);

            sort(hFences.begin(), hFences.end());

            int height;
            for (int i = 0; i < hFences.size(); ++i) {
                for (int j = i + 1; j < hFences.size(); ++j) {
                    height = hFences[j] - hFences[i];
                    if (length < height && binary_search(widths.begin(), widths.end(), height)) {
                        length = height;
                    }
                }
            }
        }

        if (length == -1) {
            return -1;
        }

        return 1ll * length * length % MOD;
    }
};