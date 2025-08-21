#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Bomb {
    int x = -1000000000;
    int power = 0;

    bool operator<(const Bomb& other) const {
        return x < other.x;
    }
};

int find_last_safe_index(const vector<Bomb>& bombs, const int idx) {
    Bomb bomb = {bombs[idx].x - bombs[idx].power, 0};
    return lower_bound(bombs.begin(), bombs.end(), bomb) - bombs.begin() - 1;
}

int count_min_unexploded_bombs(vector<Bomb>& bombs) {
    const int n = bombs.size() - 1;
    sort(bombs.begin(), bombs.end());

    vector<int> dp(n + 1);
    for (int i = 1; i <= n; ++i) {
        auto last_safe = find_last_safe_index(bombs, i);
        dp[i] = dp[last_safe] + 1;
    }

    int max_exploded_bombs = *max_element(dp.begin(), dp.end());
    int min_unexploded_bombs = n - max_exploded_bombs;

    return min_unexploded_bombs;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Bomb> bombs(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> bombs[i].x >> bombs[i].power;
    }

    cout << count_min_unexploded_bombs(bombs) << '\n';

    return 0;
}