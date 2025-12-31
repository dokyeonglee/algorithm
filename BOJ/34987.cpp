#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> p;
    vector<int> p2;
    
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        if (a + b <= m) {
            p.push_back(b);
            p2.push_back(a);
        }
    }

    sort(p.begin(), p.end());
    sort(p2.rbegin(), p2.rend());

    int answer = 0;
    int current = 0;
    int idx = 0;
    int idx2 = 0;

    for (int a = 0; a <= m; ++a) {
        int b = m - a;
        while (idx < p.size() && p[idx] == a) {
            ++current;
            ++idx;
        }
        while (idx2 < p2.size() && p2[idx2] == b + 1) {
            --current;
            ++idx2;
        }
        answer = max(answer, current);
    }

    cout << answer << '\n';

    return 0;
}