#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<pair<int, int>, int>> arr(n);
    int total = 0;
    for (auto& a : arr) {
        cin >> a.first.first >> a.first.second >> a.second;
        total += a.second;
    }

    pair<int, int> answer;

    sort(arr.begin(), arr.end());

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i].second;
        if (sum >= total - sum) {
            answer.first = arr[i].first.first;
            break;
        }
    }

    sort(arr.begin(), arr.end(), [&](const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
        return a.first.second < b.first.second;
    });

    sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i].second;
        if (sum >= total - sum) {
            answer.second = arr[i].first.second;
            break;
        }
    }

    cout << answer.first << ' ' << answer.second << '\n';

    return 0;
}