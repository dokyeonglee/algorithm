#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
using ll = long long;

ll calculate_min_penalty(int s, vector<pair<int, int>>& homework) {
    sort(homework.begin(), homework.end());

    ll penalty = 0;

    priority_queue<pair<int, int>> pq;
    int idx = 0;

    for (int i = 0; i < homework.size(); ++i) {
        while (!pq.empty() && s < homework[i].first) {
            auto [v, t] = pq.top();
            pq.pop();
            penalty += 1ll * v * (s - t);
            ++s;
        }
        s = max(s, homework[i].first);
        pq.emplace(homework[i].second, homework[i].first);
    }
 
    while (!pq.empty()) {
        auto [v, t] = pq.top();
        pq.pop();
        penalty += 1ll * v * (s - t);
        ++s;
    }

    return penalty;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, s;
        cin >> n >> s;

        vector<pair<int, int>> homework(n);
        for (int i = 0; i < n; ++i) {
            cin >> homework[i].first;
        }

        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> homework[i].second;
        }

        cout << calculate_min_penalty(s, homework) << '\n';
    }

    return 0;
}