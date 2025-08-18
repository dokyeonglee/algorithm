#include <iostream>

using namespace std;
using ll = long long;

ll count_valid_pairs(const ll sum, const ll xor_value) {
    if ((sum - xor_value) & 1 || sum < xor_value) {
        return 0;
    }

    const ll carry = (sum - xor_value) >> 1;
    if (xor_value & carry) {
        return 0;
    }

    int diff_bit_count = __builtin_popcountll(xor_value);
    return 1ll << diff_bit_count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    while (q--) {
        ll sum, xor_value;
        cin >> sum >> xor_value;
        cout << count_valid_pairs(sum, xor_value) << '\n';
    }

    return 0;
}