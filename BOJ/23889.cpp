#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> compute_prefix_sum(const vector<int>& sandcastles) {
    const int n = sandcastles.size();

    vector<int> prefix_sum(n + 1);
    for (int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + sandcastles[i - 1];
    }

    return prefix_sum;
}

vector<pair<int, int>> compute_destructions(const vector<int>& stone_starts, const vector<int>& prefix_sum) {
    const int stone_count = (int)stone_starts.size() - 1;
    vector<pair<int, int>> destructions(stone_count);

    for (int i = 0; i < stone_count; ++i) {
        const int destroy_start = stone_starts[i];
        const int destroy_end = stone_starts[i + 1] - 1;
        const int destroyed = prefix_sum[destroy_end] - prefix_sum[destroy_start - 1];
        destructions[i] = {destroyed, i};
    }

    return destructions;
}

vector<bool> select_wall_positions (vector<pair<int, int>>& destructions, const int max_walls) {
    sort(destructions.begin(), destructions.end(), [](auto& a, auto& b) {
        if (a.first != b.first) {
            return a.first > b.first;
        }
        return a.second < b.second;
    });

    const int stone_count = destructions.size();
    vector<bool> place_wall(stone_count);
    for (int i = 0; i < max_walls; ++i) {
        place_wall[destructions[i].second] = true;
    }

    return place_wall;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, max_walls, stone_count;
    cin >> n >> max_walls >> stone_count;

    vector<int> sandcastles(n);
    for (int& s : sandcastles) {
        cin >> s;
    }

    vector<int> stone_starts(stone_count + 1);
    for (int i = 0; i < stone_count; ++i) {
        cin >> stone_starts[i];
    }
    stone_starts[stone_count] = n + 1;

    auto sandcastle_prefix_sum = compute_prefix_sum(sandcastles);
    auto destructions = compute_destructions(stone_starts, sandcastle_prefix_sum);
    auto place_wall = select_wall_positions(destructions, max_walls);

    for (int i = 0; i < stone_count; ++i) {
        if (place_wall[i]) {
            cout << stone_starts[i] << '\n';
        }
    }

    return 0;
}