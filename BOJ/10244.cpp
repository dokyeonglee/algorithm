#include <iostream>
#include <vector>

using namespace std;

int _gcd(int a, int b) {
    return b ? _gcd(b, a % b) : a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> gcd(101, vector<int>(101));
    for (int i = 1; i <= 100; ++i) {
        for (int j = i; j <= 100; ++j) {
            gcd[i][j] = _gcd(i, j);
            gcd[j][i] = gcd[i][j];
        }
    }

    while (true) {
        int n;
        cin >> n;

        if (n == 0) {
            break;
        }

        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        int cnt = 0;
        vector<bool> check(101);
        for (int i = 0; i < n; ++i) {
            int g = arr[i];
            int sz = min(n, i + 100);
            for (int j = i; j < sz; ++j) {
                g = gcd[g][arr[j]];
                if (!check[g]) {
                    ++cnt;
                    check[g] = true;
                }
                if (g == 1) {
                    break;
                }
            }
            if (cnt == 100) {
                break;
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}