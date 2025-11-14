#include <iostream>
#include <vector>
#include <deque>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int& a : arr) {
        cin >> a;
    }

    deque<pair<int, int>> min_dq;
    deque<pair<int, int>> max_dq;
    for (int i = 0; i < n; ++i) {
        while (!min_dq.empty() && min_dq.back().second >= arr[i]) {
            min_dq.pop_back();
        }
        min_dq.emplace_back(i, arr[i]);
        if (min_dq.front().first <= i - k) {
            min_dq.pop_front();
        }

        while (!max_dq.empty() && max_dq.back().second <= arr[i]) {
            max_dq.pop_back();
        }
        max_dq.emplace_back(i, arr[i]);
        if (max_dq.front().first <= i - k) {
            max_dq.pop_front();
        }

        if (i >= k - 1 && max_dq.front().second - min_dq.front().second == k - 1) {
            cout << "YES\n";
            for (int j = i - k + 1; j <= i; ++j) {
                cout << arr[j] << ' ';
            }
            return 0;
        }
    }

    cout << "NO\n";

    return 0;
}