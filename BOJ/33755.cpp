#include <iostream>
#include <vector>

using namespace std;

vector<int> calculate_max_range_sum(const vector<int>& logistics) {

    const int n = logistics.size() - 1;

    vector<int> max_sum_at(n + 1);

    vector<int> max_sum_ending_at(n + 1);
    for (int i = 1; i <= n; ++i) {
        max_sum_ending_at[i] = max(max_sum_ending_at[i - 1], 0) + logistics[i];
    }

    vector<int> max_sum_starting_at(n + 2);
    for (int i = n; i >= 1; --i) {
        max_sum_starting_at[i] = max(max_sum_starting_at[i + 1], 0) + logistics[i];
    }

    for (int i = 1; i <= n; ++i) {
        max_sum_at[i] = max_sum_ending_at[i] + max_sum_starting_at[i] - logistics[i];
    }

    return max_sum_at;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> logistics(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> logistics[i];
    }

    const auto max_sum_at = calculate_max_range_sum(logistics);
    for (int i = 1; i <= n; ++i) {
        cout << max_sum_at[i] << ' ';
    }

    return 0;
}