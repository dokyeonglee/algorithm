#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> b(n);
    vector<int> f(m);

    for (int& x : b) {
        cin >> x;
    }

    for (int& x : f) {
        cin >> x;
    }

    sort(b.begin(), b.end());
    sort(f.begin(), f.end());

    int cnt = 0;
    int idx = 0;
    for (int i = 0; i < n && idx < m; ++i) {
        while (idx < m && b[i] >= f[idx]) {
            ++idx;
        }
        if (idx < m) {
            ++cnt;
            ++idx;
        }
    }

    long long answer = 0;

    cnt = min(cnt, m);
    for (int i = 1; i <= cnt; ++i) {
        answer += f[m - i];
    }

    cout << answer << '\n';

    return 0;
}