#include <iostream>
#include <vector>

using namespace std;

const int INVALID = -1;
int div2_lookup[4][4] = {
    {0, 2, 2, 5},
    {INVALID, 1, 3, 3},
    {INVALID, INVALID, 2, 4},
    {INVALID, INVALID, INVALID, 3}
};

int count_div2_in_concat(const int l, const int r) {
    if (r >= 4) {
        return r;
    }
    return div2_lookup[l][r];
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int l, r;
        cin >> l >> r;
        cout << count_div2_in_concat(l, r) << '\n';
    }

    return 0;
}