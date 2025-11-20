#include <iostream>
#include <queue>

using namespace std;

bool solve(const vector<int>& in_degree, const vector<int>& arr) {
    vector<bool> blocked(in_degree.size(), true);
    for (const int a : arr) {
        blocked[a] = false;
    }

    for (int i = 1; i < in_degree.size(); ++i) {
        if (in_degree[i] == 0 && blocked[i]) {
            return true;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> heights(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> heights[i];  
    }

    vector<int> in_degree(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        if (heights[u] > heights[v]) {
            ++in_degree[u];
        } else {
            ++in_degree[v];
        }
    }

    int k;
    cin >> k;

    vector<int> arr(k);
    for (int& a : arr) {
        cin >> a;
    }

    if (solve(in_degree, arr)) {
        cout << "flood\n";
    } else {
        cout << "no flood\n";
    }

    return 0;
}