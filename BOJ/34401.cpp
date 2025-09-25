#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int select_size(const vector<vector<int>>& group_by_size, const int seat, const ll current_time) {
    int earliest = 1e9;
    int size = -1;

    for (int i = 1; i <= seat; ++i) {
        if (group_by_size[i].empty()) {
                continue;
        }

        const int arrival = group_by_size[i].back();
        if (arrival > current_time) {
            continue;
        }

        if (earliest > group_by_size[i].back()) {
            earliest = group_by_size[i].back();
            size = i;
        }
    }

    return size;
}

ll board(vector<vector<int>>& group_by_size, int& finished_size, int seat, const ll current_time) {
    ll waiting = 0;

    while (seat > 0) {
        int size = select_size(group_by_size, seat, current_time);
        if (size == -1) {
            break;
        }

        waiting += current_time - group_by_size[size].back();
        group_by_size[size].pop_back();

        if (group_by_size[size].empty()) {
            ++finished_size;
        }

        seat -= size;
    }

    return waiting;
}

ll calculate_waiting_time(vector<vector<int>>& group_by_size, const int p) {
    const int max_seat = group_by_size.size() - 1;

    for (auto& count : group_by_size) {
        sort(count.rbegin(), count.rend());
    }

    ll current_time = 0;
    ll total_waiting = 0;

    int finished_size = 0;
    for (int i = 1; i <= max_seat; ++i) {
        if (group_by_size[i].empty()) {
            ++finished_size;
        }
    }

    while (finished_size < max_seat) {
        total_waiting += board(group_by_size, finished_size, max_seat, current_time);
        current_time += p;
    }

    return total_waiting;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p, max_seat;
    cin >> n >> p >> max_seat;

    vector<vector<int>> group_by_size(max_seat + 1);
    for (int i = 0; i < n; ++i) {
        int t, a;
        cin >> t >> a;

        group_by_size[a].push_back(t);
    }

    cout << calculate_waiting_time(group_by_size, p);

    return 0;
}