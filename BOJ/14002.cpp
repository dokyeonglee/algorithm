#include <iostream>
#include <vector>

using namespace std;

vector<int> find_lis(const vector<int>& arr) {
    const int n = arr.size();

    vector<int> lis_candidates{arr[0]};
    vector<int> dp(n, 1);

    for (int i = 1; i < n; ++i) {
        if (lis_candidates.back() < arr[i]) {
            lis_candidates.push_back(arr[i]);
            dp[i] = lis_candidates.size();
        } else {
            auto it = lower_bound(lis_candidates.begin(), lis_candidates.end(),arr[i]);
            dp[i] = it - lis_candidates.begin() + 1;
            *it = arr[i];
        }
    }

    int length = lis_candidates.size();
    vector<int> lis(length);

    for (int i = n - 1; i >= 0; --i) {
        if (dp[i] == length) {
            lis[--length] = arr[i];
        }
    }

    return lis;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int& a : arr) {
        cin >> a;
    }

    vector<int> lis = find_lis(arr);

    cout << lis.size() << '\n';
    for (const int length : lis) {
        cout << length << ' ';
    }

    return 0;
}