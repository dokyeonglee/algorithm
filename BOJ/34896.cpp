#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Bomb {
    int pos;
    int cost;

    bool operator<(const Bomb& other) {
        return pos < other.pos;
    }
};

int calculate_min_force(vector<Bomb>& bombs, const int b) {
    sort(bombs.begin(), bombs.end());

    int left = 0;
    int right = bombs.back().pos - bombs.front().pos;
    int min_force = right;

    while (left <= right) {
        const int mid = (left + right) / 2;
        int total_cost = 0;
        int current_min_cost = bombs[0].cost;

        for (int i = 1; i < bombs.size(); ++i) {
            if (bombs[i].pos - bombs[i - 1].pos <= mid) {
                current_min_cost = min(current_min_cost, bombs[i].cost);
            } else {
                total_cost += current_min_cost;
                current_min_cost = bombs[i].cost;
            }
        }

        total_cost += current_min_cost;

        if (total_cost <= b) {
            min_force = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return min_force;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Bomb> bombs(n);
    for (auto& bomb : bombs) {
        cin >> bomb.pos;
    }

    for (auto& bomb : bombs) {
        cin >> bomb.cost;
    }

    int b;
    cin >> b;

    cout << calculate_min_force(bombs, b) << '\n';

    return 0;
}