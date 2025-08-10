#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using Taste = pair<int, int>;

constexpr int MAX_SWEET = 1000000000;

pair<int, int> find_spicy_range(const vector<Taste>& tastes, int u, int v) {
    auto s = lower_bound(tastes.begin(), tastes.end(), make_pair(u, 0)) - tastes.begin();
    auto e = upper_bound(tastes.begin(), tastes.end(), make_pair(v, MAX_SWEET)) - tastes.begin();
    return {s, e};
}

int count_menus_both_like(const vector<Taste>& tastes, const pair<int, int>& spicy_range, const int x, const int y) {
    const auto [start_idx, end_idx] = spicy_range;

    int count = 0;
    for (int i = start_idx; i < end_idx; ++i) {
        if (tastes[i].second >= x && tastes[i].second <= y) {
            ++count;
        }
    }

    return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<Taste> tastes(n);
    for (auto& taste : tastes) {
        cin >> taste.first >> taste.second;
    }

    sort(tastes.begin(), tastes.end());

    while (q--) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;

        auto spicy_range = find_spicy_range(tastes, u, v);
        cout << count_menus_both_like(tastes, spicy_range, x, y) << '\n';
    }    

    return 0;
}