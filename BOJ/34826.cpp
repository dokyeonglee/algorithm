#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, s;
    cin >> n >> m >> s;

    vector<pair<int, pair<int, int>>> arr(n);
    for (auto& a : arr) {
        cin >> a.second.first;
    }

    for (auto& a : arr) {
        cin >> a.second.second;
    }

    for (int i = 0; i < n; ++i) {
        arr[i].first = i;
    }

    sort(arr.begin(), arr.end(), [](const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
        return a.second.second * b.second.first > b.second.second * a.second.first;
    });

    vector<int> answer(n);
    for (const auto& a : arr) {
        const int temp = min(s, min(a.second.first, m));
        answer[a.first] = temp;
        s -= temp;
        if (s == 0) {
            break;
        }
    }
    
    for (const int x : answer) {
        cout << x << ' ';
    }

    return 0;
}