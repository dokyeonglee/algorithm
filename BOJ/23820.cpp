#include <iostream>
#include <vector>
#include <algorithm>

constexpr int MAX_PRIME = 2000003;

using namespace std;

int product_mex(const vector<bool>& is_in_arr) {
    if (!is_in_arr[0]) {
        return 0;
    }

    if (!is_in_arr[1]) {
        return 1;
    }

    vector<bool> can_be_product(MAX_PRIME + 1);
    for (int i = 2; i <= MAX_PRIME; ++i) {
        if (!is_in_arr[i] && !can_be_product[i]) {
            return i;
        }
        if (is_in_arr[i]) {
            for (int j = 2; j * i <= MAX_PRIME; ++j) {
                if (is_in_arr[j]) {
                    can_be_product[j * i] = true;
                }
            }
        }
    }

    return MAX_PRIME;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<bool> is_in_arr(MAX_PRIME + 1);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        is_in_arr[a] = true;
    }

    cout << product_mex(is_in_arr) << '\n';

    return 0;
}