#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<pair<int, pair<int, int>>> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].second.first >> arr[i].second.second;
        arr[i].first = i;
    }

    sort(arr.begin(), arr.end(), [](const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
        if (a.second.second == b.second.second) {
            return a.second.first < b.second.first;
        }
        return a.second.second < b.second.second;
    });

    vector<int> answer(n);
    for (int i = 1; i <= 31; ++i) {
        int r = k;
        for (int j = 0; j < n; ++j) {
            if (arr[j].second.first <= i && arr[j].second.second >= i && answer[arr[j].first] == 0) {                
                answer[arr[j].first] = i;
                if (--r == 0) {
                    break;
                }
            }
        }
    }

    for (int& a : answer) {
        cout << a << '\n';
    }

    return 0;
}