#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    if (n % 2 != m % 2 || min(n, m) == 2) {
        cout << -1 << '\n';
    } else {
        vector<string> answer(n, string(m, '.'));

        for (int i = min(n, m) - 4; i >= 0; --i) {
            answer[i][i] = 'G';
            answer[i][i + 1] = 'g';
        }

        answer[min(n, m) - 3][min(n, m) - 2] = 'G';
        answer[min(n, m) - 3][min(n, m) - 1] = 'g';
        answer[min(n, m) - 2][min(n, m) - 1] = 'G';
        answer[min(n, m) - 1][min(n, m) - 1] = 'g';
        answer[min(n, m) - 1][min(n, m) - 3] = 'G';
        answer[min(n, m) - 1][min(n, m) - 2] = 'g';

        if (n < m) {
            for (int i = n; i < m; ++i) {
                answer[0][i] = 'G';
                answer[1][i] = 'g';
            }
        } else {
            for (int i = m; i < n; ++i) {
                answer[i][0] = 'G';
                answer[i][1] = 'g';
            }
        }

        cout << max(n, m) << '\n';
        for (int i = 0; i < n; ++i) {
            cout << answer[i] << '\n';
        }
    }

    return 0;
}