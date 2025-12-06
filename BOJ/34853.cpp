#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_jth_element(const vector<vector<int>>& arr, const int a, const int b, const int c, const int j) {
    int left = 0;
    int right = 1e9;
    int jth_element = 0;

    while (left <= right) {
        const int mid = (left + right) / 2;
        const int cnt =   upper_bound(arr[a].begin(), arr[a].end(), mid) - arr[a].begin()
                      +   upper_bound(arr[b].begin(), arr[b].end(), mid) - arr[b].begin()
                      +   upper_bound(arr[c].begin(), arr[c].end(), mid) - arr[c].begin();
        if (cnt >= j) {
            jth_element = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return jth_element;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<vector<int>> arr(n + 1);
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;

        arr[i].resize(k);
        for (int& a : arr[i]) {
            cin >> a;
        }

        sort(arr[i].begin(), arr[i].end());
    }

    while (q--) {
        int a, b, c, j;
        cin >> a >> b >> c >> j;

        cout << find_jth_element(arr, a, b, c, j) << '\n';
    }

    return 0;
}