#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

bool radius_diff_within_k(const ll squared_distance1, const ll squared_distance2, const ll k) {
    ll delta = squared_distance2 - squared_distance1 - k * k;
    return delta < 0 || delta * delta <= 4 * k * k * squared_distance1;
}

vector<ll> read_squared_distances(const int n) {
    vector<ll> squared_distances(n);
    for (ll& squared_distance : squared_distances) {
        int x, y;
        cin >> x >> y;
        squared_distance = x * x + y * y;
    }

    sort(squared_distances.begin(), squared_distances.end());

    return squared_distances;
}

int max_points_count(const vector<ll>& squared_distances, const int k) {
    int left = 0;
    int max_points = 1;

    for (int right = 0; right < squared_distances.size(); ++right) {
        while (left < right && !radius_diff_within_k(squared_distances[left], squared_distances[right], k)) {
            ++left;
        }
        max_points = max(max_points, right - left + 1);
    }

    return max_points;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    auto squared_distances = read_squared_distances(n);
    int max_points = max_points_count(squared_distances, k);

    cout << fixed;
    cout.precision(10);
    cout << 100.0 / n * max_points;

    return 0;
}