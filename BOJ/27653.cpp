#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    ll operations = 0;
    vector<int> weights(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> weights[i];
        operations += weights[i];
    }

    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;

        operations -= min(weights[u], weights[v]);
    }

    cout << operations << '\n';

    return 0;
}