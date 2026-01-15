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

    vector<int> prefix_max(n + 1);
    vector<int> suffix_max(n + 2);

    for (int i = 1; i <= n; ++i) {
        prefix_max[i] = max(prefix_max[i - 1], arr[i]);
    }
    for (int i = n; i >= 1; --i) {
        suffix_max[i] = max(suffix_max[i + 1], arr[i]);
    }

    int answer = 1e9;
    for (int i = 2; i <= n - 2; ++i) {
        answer = min(answer, prefix_max[i] + suffix_max[i + 1] + min(arr[1], arr[i]) + min(arr[i + 1], arr[n]));
    }

    cout << answer << '\n';

    return 0;
}