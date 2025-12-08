#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string str;
    cin >> str;

    vector<bool> check(1 << 18);
    for (int i = 0; i < n; ++i) {
        int x = 0;
        for (int j = 0; j < 18 && i + j < n; ++j) {
            x = 2 * x + (str[i + j] - '0');
            check[x] = true;
        }
    }

    for (int i = 1; i < check.size(); ++i) {
        if (!check[i]) {
            int temp = i;
            string answer;
            while (temp > 0) {
                answer += '0' + temp % 2;
                temp /= 2;
            }
            reverse(answer.begin(), answer.end());
            cout << answer << '\n';
            return 0;
        }
    }

    return 0;
}