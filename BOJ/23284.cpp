#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

void solve(vector<int>& result, vector<bool>& visited, int x, int depth) {
    visited[x] = true;
    result[depth] = x;

    if (depth == result.size() - 1) {
        for (int i = 1; i < result.size(); ++i) {
            cout << result[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = x - 1; i >= 1; --i) {
        if (!visited[i]) {
            solve(result, visited, i, depth + 1);
            visited[i] = false;
            break;
        }
    }
    for (int i = x + 1; i < result.size(); ++i) {
        if (!visited[i]) {
            solve(result, visited, i, depth + 1);
            visited[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        vector<int> result(n + 1);
        vector<bool> visited(n + 1);
        solve(result, visited, i, 1);
    }

    return 0;
}