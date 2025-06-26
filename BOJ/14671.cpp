#include <iostream>
#include <vector>

using namespace std;

constexpr int ALL_PARITY_MASK = 0xF;

int parity_index(int x, int y) {
    return ((x & 1) << 1) | ((x + y) & 1);
}

bool should_clean(const vector<pair<int, int>>& molds) {
    int parity_mask = 0;
    for (auto& mold : molds) {
        parity_mask |= (1 << parity_index(mold.first, mold.second));
        if (parity_mask == ALL_PARITY_MASK) {
            return true;
        }
    }
    return parity_mask == ALL_PARITY_MASK;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, mold_count;
    cin >> n >> m >> mold_count;

    vector<pair<int, int>> molds(mold_count);
    for (auto& mold : molds) {
        cin >> mold.first >> mold.second;
    }

    if (should_clean(molds)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}