#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> degree(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        ++degree[u];
        ++degree[v];
    }

    int answer = 0;
    for (int i = 1; i <= n; ++i) {
        answer += max(0, degree[i] - 2);
    }

    cout << answer << '\n';

    return 0;
}