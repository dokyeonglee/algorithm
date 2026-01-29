#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, pair<int, int>>> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].second.first >> arr[i].second.second;
        arr[i].first = i + 1;
    }

    sort(arr.begin(), arr.end(), [&](const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
        if (a.second.first * b.second.second == b.second.first * a.second.second) {
            return a.first < b.first;
        }
        return a.second.first * b.second.second < b.second.first * a.second.second;
    });

    for (int i = 0; i < n; ++i) {
        cout << arr[i].first << ' ';
    }

    return 0;
}