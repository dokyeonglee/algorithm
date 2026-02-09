#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p;
    cin >> n >> p;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    int sum = 0;
    priority_queue<int> pq;
    for (int i = 1; i <= n; ++i) {
        sum += arr[i];
        pq.push(-arr[i]);
        while (!pq.empty() && sum + pq.top() >= p) {
            sum -= -pq.top();
            pq.pop();
        }
        if (sum < p) {
            cout << -1 << ' ';
        } else {
            cout << pq.size() << ' ';
        }
    }

    return 0;
}