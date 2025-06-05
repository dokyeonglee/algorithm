#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int find_parent(vector<int>& parent, int x){
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find_parent(parent, parent[x]);
}

void union_parent(vector<int>& parent, vector<int>& exit_costs, int x, int y){
    x = find_parent(parent, x);
    y = find_parent(parent, y);
    if (x != y) {
        if (exit_costs[x] > exit_costs[y]) {
            swap(x, y);
        }
        exit_costs[y] = exit_costs[x];
        parent[y] = x;
    }
}

ll try_install_warp(const pair<int, pair<int, int>>& warp, vector<int>& parent, vector<int>& exit_costs) {

    int pu = find_parent(parent, warp.second.first);
    int pv = find_parent(parent, warp.second.second);
    int c = warp.first;

    if (pu != pv) {
        if (exit_costs[pu] + exit_costs[pv] >= c + min(exit_costs[pu], exit_costs[pv])) {
            union_parent(parent, exit_costs, pu, pv);
            return c;
        }
    }

    return 0;
}

ll install_warp(vector<pair<int, pair<int, int>>>& warps, vector<int>& parent, vector<int>& exit_costs) {

    sort(warps.begin(), warps.end());

    ll total_time = 0;
    for (auto& warp : warps) {
        total_time += try_install_warp(warp, parent, exit_costs);
    }

    return total_time;
}

ll install_emergency_exits(vector<int>& parent, const vector<int>& exit_costs) {

    ll total_time = 0;
    for (int i = 1; i < parent.size(); ++i) {
        if (find_parent(parent, i) == i) {
            total_time += exit_costs[i];
        }
    }

    return total_time;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    vector<pair<int, pair<int, int>>> warps(m);
    for (auto& warp : warps) {
        cin >> warp.second.first >> warp.second.second >> warp.first;
    }

    vector<int> exit_costs(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> exit_costs[i];
    }

    ll total_time = install_warp(warps, parent, exit_costs) + install_emergency_exits(parent, exit_costs);
    cout << total_time << '\n';

    return 0;
}