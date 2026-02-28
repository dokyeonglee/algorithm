#include <iostream>
#include <vector>

using namespace std;

constexpr int INF = 1e8;

vector<int> solve(const int n) {
    if (n == 1 || n == 2 || n == 4 || n == 7) {
        return {INF, INF, INF};
    }
    if (n == 12) {
        return {4, 0, 0};
    }
    switch (n % 8) {
        case 0:
            return {0, 0, n / 8};
        case 1:
            return {3, 0, n / 8 - 1};
        case 2:
            return {0, 2, n / 8 - 1};
        case 3:
            return {1, 0, n / 8};
        case 4:
            return {0, 4, n / 8 - 2};
        case 5:
            return {0, 1, n / 8};
        case 6:
            return {2, 0, n / 8};
        case 7:
            return {0, 3, n / 8 - 1};
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    vector<string> answer;

    while (t--) {
        int n;
        cin >> n;

        string result;
        auto cnt = solve(n);
        if (cnt[0] == INF) {
            result = "-1";
        } else {
            for (int i = 0; i < cnt[0]; ++i) {
                result += '3';
            }
            for (int i = 0; i < cnt[1]; ++i) {
                result += '5';
            }
            for (int i = 0; i < cnt[2]; ++i) {
                result += '8';
            }
        }
        answer.push_back(result);
    }

    for (auto& a : answer) {
        cout << a << '\n';
    }

    return 0;
}