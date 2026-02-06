#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

constexpr ll MAX_HP = 1e13;

ll solve(const vector<int>& monsters, const string& scroll_types, const vector<int>& scroll_values) {
    ll result = MAX_HP;
    ll left = 1;
    ll right = MAX_HP;

    while (left <= right) {
        const ll mid = (left + right) / 2;
        bool can_clear = true;
        ll hp = mid;

        for (int i = 0; i < monsters.size(); ++i) {
            if (hp <= monsters[i]) {
                can_clear = false;
                break;
            }

            hp -= monsters[i];
            if (scroll_types[i] == '+') {
                hp += scroll_values[i];
            } else if (scroll_types[i] == '*') {
                if (hp >= (MAX_HP + scroll_values[i] - 1) / scroll_values[i]) {
                    break;
                }
                hp *= scroll_values[i];
            }
            if (hp >= MAX_HP) {
                break;
            }
        }

        if (can_clear) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> monsters(n);
        for (int& monster : monsters) {
            cin >> monster;
        }

        string scroll_types;
        cin >> scroll_types;

        vector<int> scroll_values(n);
        for (int& r : scroll_values) {
            cin >> r;
        }

        cout << solve(monsters, scroll_types, scroll_values) << '\n';
    }

    return 0;
}