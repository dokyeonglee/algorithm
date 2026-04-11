#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    int answer = 0;
    for (int i = 1; i <= n; ++i) {
        answer += max(arr[i] - arr[i - 1], 0);
    }

    cout << answer;

    return 0;
}