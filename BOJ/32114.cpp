#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> w(n + 1);

    for(int i = 1; i < n; i++){
        cin >> w[i];
    }

    vector<int> cnt(n + 1);

    for(int i = 0; i < m; i++){
        int u, v, x;
        cin >> u >> v >> x;
        cnt[u] += x;
        cnt[v] -= x;
    }

    for(int i = 1; i <= n; i++){
        cnt[i] += cnt[i - 1];
    }

    for(int i = 1; i < n; i++){
        cout << 1ll * (cnt[i] / w[i]) * (cnt[i] / w[i]) * (w[i] - cnt[i] % w[i]) + 1ll * (cnt[i] / w[i] + 1) * (cnt[i] / w[i] + 1) * (cnt[i] % w[i]) << "\n";
    }

    return 0;
}