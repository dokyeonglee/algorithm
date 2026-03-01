#include <iostream>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int dijkstra(const vector<int>& src, const vector<pair<int, pair<int, int>>>& swap_table) {
    map<vector<int>, int> mp;
    mp[src] = 0;

    priority_queue<pair<int, vector<int>>> pq;
    pq.emplace(0, src);

    while (!pq.empty()) {
        auto [dist, v] = pq.top();
        pq.pop();

        dist = -dist;

        if (mp[v] < dist) {
            continue;
        }

        for (auto& swap_info : swap_table) {
            swap(v[swap_info.second.first], v[swap_info.second.second]);
            if (mp.count(v) == 0 || mp[v] > dist + swap_info.first) {
                mp[v] = dist + swap_info.first;
                pq.emplace(-(dist + swap_info.first), v);
            }
            swap(v[swap_info.second.first], v[swap_info.second.second]);
        }
    }

    auto v(src);
    sort(v.begin() + 1, v.end());

    if (mp.count(v) == 0) {
        return -1;
    }

    return mp[v];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    int m;
    cin >> m;

    vector<pair<int, pair<int, int>>> swap_table(m);
    for (auto& swap_info : swap_table) {
        cin >> swap_info.second.first >> swap_info.second.second >> swap_info.first;
    }

    cout << dijkstra(arr, swap_table);

    return 0;
}