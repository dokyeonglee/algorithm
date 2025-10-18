#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> robots(n, vector<int>(2));
    for (auto& robot : robots) {
        cin >> robot[0] >> robot[1];
    }

    vector<int> ship(2);
    cin >> ship[0] >> ship[1];

    char c;
    cin >> c;

    ll answer = 0;
    vector<int> seat = ship;
    int d = 0;

    if (c == 'N') {
        d = 1;
    }

    sort(robots.begin(), robots.end(), [&](const vector<int>& a, const vector<int>& b) {
        return a[d] < b[d];
    });

    for (int i = 0; i < n; ++i) {
        answer += abs(robots[i][0] - seat[0]) + abs(robots[i][1] - seat[1]);
        ++seat[d];
    }

    cout << answer << '\n';

    return 0;
}