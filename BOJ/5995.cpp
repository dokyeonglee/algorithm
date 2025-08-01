#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

constexpr int MAX_HAY_WEIGHT_LIMIT = 45000;

int calculate_consumable_weight(const vector<int>& hay_weights, const int max_allowed_weight) {
    bitset<MAX_HAY_WEIGHT_LIMIT + 1> is_consumable;
    is_consumable[0] = 1;

    for (const int weight : hay_weights) {
        is_consumable |= (is_consumable << weight);

        if (is_consumable[max_allowed_weight]) {
            return max_allowed_weight;
        }
    }

    for (int i = max_allowed_weight; i > 0; --i) {
        if (is_consumable[i]) {
            return i;
        }
    }

    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int max_allowed_weight, hay_count;
    cin >> max_allowed_weight >> hay_count;

    vector<int> hay_weights(hay_count);
    for (int& weight : hay_weights) {
        cin >> weight;
    }

    cout << calculate_consumable_weight(hay_weights, max_allowed_weight);

    return 0;
}