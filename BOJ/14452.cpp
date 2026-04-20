#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    cin >> n >> t;

    vector<int> arr(n);
    for(int& a : arr) {
        cin >> a;
    }

    int left = 1;
    int right = n;
    int answer = n;

    while (left <= right) {
        int mid = (left + right) / 2;
        int result = *max_element(arr.begin(), arr.begin() + mid);
        priority_queue<int, vector<int>, greater<>> pq(arr.begin(), arr.begin() + mid);

        for (int i = mid; i < n; ++i) {
            int x = pq.top() + arr[i];
            pq.pop();
            pq.push(x);
            result = max(result, x);
        }

        if (result <= t) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << answer;

    return 0;
}