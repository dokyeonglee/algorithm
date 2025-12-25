#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int& a : arr) {
        cin >> a;
    }

    if (n == 1) {
        cout << arr[0] << '\n';
        return 0;
    }

    sort(arr.begin(), arr.end());

    cout << arr[n - 2] << '\n';
    for (int i = 1; i < n; i += 2) {
        cout << arr[i - 1] << ' ' << arr[i] << ' ' << arr[i + 1] << '\n';
        arr[i + 1] = arr[i];
    }

    return 0;
}