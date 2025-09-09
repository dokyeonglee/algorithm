#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

constexpr int ROOT = 1;

void calculate_xor_distances(const vector<vector<pair<int, int>>>& tree, vector<int>& xor_distances, const int now, const int parent) {
    for (const auto [next, cost] : tree[now]) {
        if (next != parent) {
            xor_distances[next] = (xor_distances[now] ^ cost);
            calculate_xor_distances(tree, xor_distances, next, now);
        }
    }
}

ll count_special_pairs(vector<int>& xor_distances) {
    sort(xor_distances.begin(), xor_distances.end());

    int cnt = 1;
    ll pairs = 0;

    for (int i = ROOT + 1; i < xor_distances.size(); ++i) {
        if (xor_distances[i] == xor_distances[i - 1]) {
            pairs += cnt;
            ++cnt;
        } else {
            cnt = 1;
        }
    }

    return pairs;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<pair<int, int>>> tree(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        
        tree[u].emplace_back(v, c);
        tree[v].emplace_back(u, c);
    }

    vector<int> xor_distances(n + 1);

    calculate_xor_distances(tree, xor_distances, ROOT, -1);

    cout << count_special_pairs(xor_distances) << '\n';

    return 0;
}