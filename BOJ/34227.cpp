#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int count_walkovers(ll teams) {
    int walkovers = 0;
    while (teams > 1) {
        walkovers += (teams & 1);
        teams = ((teams + 1) >> 1);
    }
    return walkovers;
}

ll find_best_team_count(const ll a, const ll b) {
    if (__builtin_clzll(a) != __builtin_clzll(b)) {
        return 1ll << (64 - __builtin_clzll(a));
    }

    ll first_different_bit = (1ll << (63 - __builtin_clzll(a ^ b)));

    if ((first_different_bit - 1) & a) {
        return b & -first_different_bit;
    } else {
        return a;
    }
}

int min_walkovers(const ll a, const ll b) {
    ll teams = find_best_team_count(a, b);
    return count_walkovers(teams);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        ll a, b;
        cin >> a >> b;
        cout << min_walkovers(a, b) << '\n';
    }

    return 0;
}