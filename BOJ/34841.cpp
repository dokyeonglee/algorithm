#include <iostream>
#include <vector>
#include <set>

using namespace std;

int gcd(const int a, const int b) {
    return b ? gcd(b, a % b) : a;
}

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
        cout << 1 << '\n';
        return 0;
    }

    vector<int> answer(n);
    answer[0] = 1;
    answer[1] = 1;

    set<int> s{arr[0], arr[1]};

    int g = abs(arr[1] - arr[0]);
    int min_value = min(arr[0], arr[1]);
    int max_value = max(arr[0], arr[1]);

    for (int i = 2; i < n; ++i) {
        s.insert(arr[i]);
        min_value = min(min_value, arr[i]);
        max_value = max(max_value, arr[i]);
        g = gcd(g, abs(arr[i] - arr[i - 1]));
        if (max_value - min_value == 1ll * g * i && (s.size() == 1 || s.size() == i + 1)) {
            answer[i] = 1;
        }
    }

    for (const int x : answer) {
        cout << x << '\n';
    }

    return 0;
}