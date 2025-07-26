#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int MIN_VALUE = 1;
constexpr int MAX_MODIFICATIONS = 3;

struct LISInfo {
    int length;
    vector<int> lis_length;
};

LISInfo compute_lis_info(const vector<int>& arr) {
    const int n = arr.size() - 1;

    vector<int> lis_min_ends{arr[1]};
    vector<int> lis_length(n + 1);

    lis_length[1] = 1;

    for (int i = 2; i <= n; ++i) {
        if (arr[i] >= lis_min_ends.back()) {
            lis_min_ends.push_back(arr[i]);
            lis_length[i] = lis_min_ends.size();
        } else {
            auto it = upper_bound(lis_min_ends.begin(), lis_min_ends.end(), arr[i]);
            lis_length[i] = it - lis_min_ends.begin() + 1;
            *it = arr[i];
        }
    }

    return {lis_min_ends.size(), lis_length};
}

vector<bool> mark_lis_elements(const LISInfo& lis_info) {
    const int n = lis_info.lis_length.size() - 1;
    vector<bool> is_in_lis(n + 1);

    for (int i = n, target = lis_info.length; i >= 1 && target > 0; --i) {
        if (lis_info.lis_length[i] == target) {
            is_in_lis[i] = true;
            --target;
        }
    }

    return is_in_lis;
}

vector<pair<int, int>> plan_modifications(const vector<int>& arr, const vector<bool>& is_in_lis) {
    const int n = arr.size() - 1;

    vector<pair<int, int>> modification_plans;

    int max_so_far = MIN_VALUE;
    for (int i = 1; i <= n; ++i) {
        if (!is_in_lis[i]) {
            modification_plans.emplace_back(i, max_so_far);
        } else {
            max_so_far = max(max_so_far, arr[i]);
        }
    }

    return modification_plans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    auto lis_info = compute_lis_info(arr);
    int modification_count = n - lis_info.length;

    if (modification_count > MAX_MODIFICATIONS) {
        cout << "NO\n";
        return 0;
    }

    auto is_in_lis = mark_lis_elements(lis_info);
    auto modifications_plans = plan_modifications(arr, is_in_lis);

    cout << "YES\n";
    cout << modifications_plans.size() << '\n';
    for (const auto& [idx, new_value] : modifications_plans) {
        cout << idx << ' ' << new_value << '\n';
    }

    return 0;
}