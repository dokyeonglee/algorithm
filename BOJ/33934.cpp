#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int find_left_limit(const vector<int>& stone_counts, int s) {
    for (int i = s - 1; i >= 0; --i) {
        if (stone_counts[i] == 1) {
            return i;
        }
    }
    return 0;
}

int find_right_limit(const vector<int>& stone_counts, int e) {
    for (int i = e - 1; i < stone_counts.size(); ++i) {
        if (stone_counts[i] == 1) {
            return i;
        }
    }
    return stone_counts.size() - 1;
}

bool can_reach_with_k_steps(const vector<int>& stone_counts, const int k, int s, int e) {

    if (s > e) {
        swap(s, e);
    }

    int min_steps = e - s + 1;

    if (k < min_steps) {
        return false;
    }

    int left = find_left_limit(stone_counts, s);
    int right = find_right_limit(stone_counts, e);
    int max_steps = accumulate(stone_counts.begin() + left, stone_counts.begin() + right + 1, 0);

    return k <= max_steps;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, s, e;
    cin >> n >> s >> e;

    vector<int> stone_counts(n);
    for (auto& count : stone_counts) {
        cin >> count;
    }

    int k;
    cin >> k;

    cout << can_reach_with_k_steps(stone_counts, k, s, e) << '\n';

    return 0;
}