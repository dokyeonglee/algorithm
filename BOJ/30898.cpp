#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;


int max_pluggable_chargers(vector<int>& charger_lengths, const int sockets) {
    if (sockets <= 2 || charger_lengths.size() <= 2) {
        return min(sockets, (int)charger_lengths.size());
    }

    sort(charger_lengths.begin(), charger_lengths.end());

    ll temp = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 0; i < charger_lengths.size() - 2; ++i) {
        temp += charger_lengths[i] / 3;
        if (charger_lengths[i] % 3 == 1) {
            cnt1++;
        } else if (charger_lengths[i] % 3 == 2) {
            cnt2++;
        }
        if (temp + cnt2 + max(0, (cnt1 - cnt2 + 1) / 2) + 2 > sockets) {
            return i + 2;
        }
    }

    return charger_lengths.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s;
    cin >> n >> s;

    vector<int> charger_lengths(n);
    for (int& charger : charger_lengths) {
        cin >> charger;
    }

    cout << max_pluggable_chargers(charger_lengths, s) << '\n';

    return 0;
}