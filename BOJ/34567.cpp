#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

constexpr int ROOT = 1;

int move_to_root(vector<int>& parent, vector<ll>& arr, const int now) {
    if (now == ROOT) {
        return ROOT;
    }

    if (arr[now] > 0) {
        arr[parent[now]] += arr[now];
        arr[now] = 0;
        return parent[now] = move_to_root(parent, arr, parent[now]);
    }

    return now;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> parent(n + 1);
    vector<ll> arr(n + 1);

    for (int i = 2; i <= n; ++i) {
        char t;
        int a, p;
        cin >> t >> a >> p;

        if (t == 'W') {
            arr[i] = -a;
        } else if (t == 'S') {
            arr[i] = a;
        }

        parent[i] = p;
    }

    for (int i = 2; i <= n; ++i) {
        if (arr[i] > 0) {
            move_to_root(parent, arr, i);
        }
    }

    cout << arr[1] << '\n';

    return 0;
}