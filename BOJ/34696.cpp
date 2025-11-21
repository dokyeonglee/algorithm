#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

constexpr ll INF = 1e18;

ll calculate_squared_distance(const pair<int, int>& a, const pair<int, int>& b) {
    return 1ll * (a.first - b.first) * (a.first - b.first) + 1ll * (a.second - b.second) * (a.second - b.second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> arr(m + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> arr[i].first >> arr[i].second;
    }

    int s;
    cin >> s;

    vector<ll> min_squared_distance(m + 1, INF);
    for (int i = 1; i <= m; ++i) {
        min_squared_distance[i] = calculate_squared_distance(arr[s], arr[i]);
    }

    vector<int> answer{s};
    for (int i = 1; i < n; ++i) {
        ll temp = -INF;
        int idx = i;
        for (int j = 1; j <= m; ++j) {
            if (min_squared_distance[j] > temp) {
                idx = j;
                temp = min_squared_distance[j];
            }
        }

        answer.push_back(idx);
        min_squared_distance[idx] = -INF;

        for (int j = 1; j <= m; ++j) {
            min_squared_distance[j] = min(min_squared_distance[j], calculate_squared_distance(arr[idx], arr[j]));
        }
    }

    for (const int x : answer) {
        cout << x << '\n';
    }

    return 0;
}