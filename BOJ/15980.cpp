#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> birds(n);
    vector<int> d(n);
    vector<int> sum(m);
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c >> birds[i];
        if (c == 'L') {
            d[i] = -1;
        } else {
            d[i] = 1;
        }
        for (int j = 0; j < m; ++j) {
            if (birds[i][j] == '1') {
                sum[j] += d[i];
            }
        }
    }

    int idx = -1;
    int answer = 1e9;
    for (int i = 0; i < n; ++i) {
        int center = 0;
        int interruption = 0;
        for (int j = 0; j < m; ++j) {
            int new_sum = sum[j];
            if (birds[i][j] == '1') {
                new_sum -= d[i];
            }
            center += new_sum;
            interruption = max(interruption, abs(center));
        }
        if (interruption < answer) {
            answer = interruption;
            idx = i + 1;
        }
    }

    cout << idx << '\n';
    cout << answer << '\n';

    return 0;
}