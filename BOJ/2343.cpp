#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> lessons(n);
    for (int i = 0; i < n; ++i) {
        cin >> lessons[i];
    }

    int left = *max_element(lessons.begin(), lessons.end());
    int right = 1e9;
    int answer = right;

    while (left <= right) {
        const int mid = (left + right) / 2;
        int cnt = 1;
        int sum = 0;

        for (int i = 0; i < n; ++i) {
            if (sum + lessons[i] <= mid) {
                sum += lessons[i];
            } else {
                ++cnt;
                sum = lessons[i];
            }
        }

        if (cnt <= m) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << answer << '\n';

    return 0;
}