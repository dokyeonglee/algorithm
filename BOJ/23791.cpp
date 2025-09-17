#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lower_bound_kth_in_first(const vector<int>& arr1, const vector<int>& arr2, const int i, const int j, const int k) {
    int left = 0;
    int right = min(i, k);
    int idx = -1;

    while (left <= right) {
        const int mid = (left + right) / 2;
        if (k - mid <= j && arr1[mid] >= arr2[k - mid]) {
            idx = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return idx;
}

int count_le(const vector<int>& arr, const int s, const int e, const int x) {
    return upper_bound(arr.begin() + s, arr.begin() + e, x) - arr.begin() - s;
}

pair<int, int> kth_element(const vector<int>& arr1, const vector<int>& arr2, const int i, const int j, const int k) {
    const int idx = lower_bound_kth_in_first(arr1, arr2, i, j, k);
    const int cnt = idx + count_le(arr2, 1, j + 1, arr1[idx]);

    if (idx != -1 && cnt == k) {
        return {1, idx};
    }
    return {2, lower_bound_kth_in_first(arr2, arr1, j, i, k)};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> korean_foods(n + 1);
    for (int i = 1; i <= n; ++i) {  
        cin >> korean_foods[i];
    }

    vector<int> western_foods(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> western_foods[i];
    }
    
    int q;
    cin >> q;

    while (q--) {
        int i, j, k;
        cin >> i >> j >> k;

        const auto [food_type, idx] = kth_element(korean_foods, western_foods, i, j, k);
        cout << food_type << ' ' << idx << '\n';
    }

    return 0;
}