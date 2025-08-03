#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int INF = 1e9;
constexpr int GROUP_MIN = 1;
constexpr int GROUP_MAX = 3;

int min_in_range(const vector<int>& arr, const int s, const int e) {
    return *min_element(arr.begin() + s, arr.begin() + e + 1);
}

int calculate_min_changes(const vector<int>& dining_groups) {
    const int n = dining_groups.size() - 1;

    vector<vector<int>> to_ascending(2, vector<int>(GROUP_MAX + 1));
    vector<vector<int>> to_descending(2, vector<int>(GROUP_MAX + 1));

    int toggle = 0;

    for (int i = 1; i <= n; ++i) {
        toggle ^= 1;

        fill(to_ascending[toggle].begin(), to_ascending[toggle].end(), INF);
        fill(to_descending[toggle].begin(), to_descending[toggle].end(), INF);

        for (int j = GROUP_MIN; j <= GROUP_MAX; ++j) {
            to_ascending[toggle][j] = min_in_range(to_ascending[toggle ^ 1], GROUP_MIN, j);
            to_descending[toggle][j] = min_in_range(to_descending[toggle ^ 1], j, GROUP_MAX);

            if (j != dining_groups[i]) {
                ++to_ascending[toggle][j];
                ++to_descending[toggle][j];
            }
        }
    }

    int changes_to_ascending = min_in_range(to_ascending[toggle], GROUP_MIN, GROUP_MAX);
    int changes_to_descending = min_in_range(to_descending[toggle], GROUP_MIN, GROUP_MAX);
    int min_changes = min(changes_to_ascending, changes_to_descending);

    return min_changes;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> dining_groups(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> dining_groups[i];
    }

    cout << calculate_min_changes(dining_groups) << '\n';

    return 0;
}