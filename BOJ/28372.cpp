#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const vector<int> dices = {4, 6, 8, 12, 20};

int main() {
    vector<int> cnt(dices.size());
    for (int& x : cnt) {
        cin >> x;
    }

    vector<long double> dp(501);
    dp[0] = 1;

    for (int x = 0; x < dices.size(); ++x) {
        for (int i = 0; i < cnt[x]; ++i) {
            for (int j = 500; j >= 0; --j) {
                dp[j] = 0;
                for (int k = 1; k <= dices[x] && k <= j; ++k) {
                    dp[j] += dp[j - k];
                }
            }
        }
    }

    vector<pair<long double, int>> arr(501);
    for (int i = 0; i < arr.size(); ++i) {
        arr[i].first = dp[i];
        arr[i].second = i;
    }

    sort(arr.rbegin(), arr.rend());

    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i].first) {
            cout << arr[i].second << ' ';
        }
    }

    return 0;
}   