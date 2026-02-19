#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, w;
    cin >> n >> w;
    
    vector<int> cnt(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        ++cnt[u];
        ++cnt[v];
    }

    int leaves = 0;
    for (int i = 2; i <= n; ++i) {
        if (cnt[i] == 1) {
            ++leaves;
        }
    }

    cout << fixed;
    cout.precision(10);
    cout << 1.0 * w / leaves;

    return 0;
}