#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

ll compute_mex(const vector<pair<int, int>>& coins, const int count) {
    ll mex = 1;
    for (const auto& coin : coins) {
        if (coin.second >= count) {
            continue;
        }
        if (coin.first > mex) {
            break;
        }
        mex += coin.first;
    }

    return mex;
}

int find_min_coin_count(vector<pair<int, int>>& coins, const int k) {
    sort(coins.begin(), coins.end());

    int coin_count = -1;
    int left = 0;
    int right = coins.size();

    while (left <= right) {
        int mid = (left + right) / 2;
        if (compute_mex(coins, mid) <= k) {
            left = mid + 1;
        } else {
            coin_count = mid;
            right = mid - 1;
        }
    }

    return coin_count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<pair<int, int>> coins(n);
        for (int i = 0; i < n; ++i) {
            cin >> coins[i].first;
            coins[i].second = i;
        }

        cout << find_min_coin_count(coins, k) << '\n';
    }

    return 0;
}