#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct SwordRequirement {
    int right;
    int left_min;
    int left_max;
};

int calculate_min_swords(const vector<SwordRequirement>& sword_requirements) {
    const int n = sword_requirements.size();

    vector<int> right_swords(n);
    for (int i = 0; i < n; ++i) {
        right_swords[i] = sword_requirements[i].right;
    }

    sort(right_swords.begin(), right_swords.end());
    right_swords.erase(unique(right_swords.begin(), right_swords.end()), right_swords.end());

    vector<pair<int, int>> left_sword_ranges;
    for (const auto& [right, left_min, left_max] : sword_requirements) {
        auto it1 = lower_bound(right_swords.begin(), right_swords.end(), left_min);
        auto it2 = upper_bound(right_swords.begin(), right_swords.end(), left_max);

        if (it1 == it2 || ((it2 - it1) == 1 && *it1 == right)) {
            left_sword_ranges.emplace_back(left_min, left_max);
        }
    }

    sort(left_sword_ranges.begin(), left_sword_ranges.end());

    int sword_count = right_swords.size();
    pair<int, int> current_range;

    for (const auto& [left_min, left_max] : left_sword_ranges) {
        if (current_range.second < left_min) {
            ++sword_count;
            current_range = {left_min, left_max};
        } else {
            current_range.first = left_min;
            current_range.second = min(current_range.second, left_max);
        }
    }

    return sword_count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<SwordRequirement> sword_requirements(n);
    
    for (auto& two_sword : sword_requirements) {
        cin >> two_sword.right >> two_sword.left_min >> two_sword.left_max;
    }

    cout << calculate_min_swords(sword_requirements) << '\n';

    return 0;
}