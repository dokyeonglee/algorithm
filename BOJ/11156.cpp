#include <iostream>
#include <vector>
#include <array>

using namespace std;

constexpr int MAX_CANDY_TYPES = 200;
constexpr int MOD = 65537;
constexpr array<int, MAX_CANDY_TYPES + 1> pow2_mod = [] {
    array<int, MAX_CANDY_TYPES + 1> result{};
    result[0] = 1;

    for (int i = 1; i <= MAX_CANDY_TYPES; ++i) {
        result[i] = result[i - 1] * 2 % MOD;
    }
    return result;
}();

int mod_add(const int a, const int b) {
    int sum = (a + b);
    if (sum >= MOD) {
        return sum - MOD;
    }
    return sum;
}

int mod_sub(const int a, const int b) {
    int sub = (a - b);
    if (sub < 0) {
        return sub + MOD;
    }
    return sub;
}

int count_ways_to_spend_at_least_c(const vector<int>& costs, const int c) {
    vector<int> ways_to_spend(c);
    ways_to_spend[0] = 1;

    for (const int cost : costs) {
        for (int i = c - 1 - cost; i >= 0; --i) {
            ways_to_spend[i + cost] = mod_add(ways_to_spend[i + cost], ways_to_spend[i]); 
        }
    }

    const int all_combinations = pow2_mod[costs.size()];

    int ways_to_less_than_c = 0;
    for (int w : ways_to_spend) {
        ways_to_less_than_c = mod_add(ways_to_less_than_c, w);
    }

    return mod_sub(all_combinations, ways_to_less_than_c);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, c;
        cin >> n >> c;

        vector<int> costs(n);
        for (int& cost : costs) {
            cin >> cost;
        }

        cout << count_ways_to_spend_at_least_c(costs, c) << '\n';
    }

    return 0;
}