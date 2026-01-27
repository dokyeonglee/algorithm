#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d;
    cin >> n >> d;

    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; ++i) {
        int c;
        cin >> c;

        ++cnt[c];
    }

    int answer = 0;
    for (int i = 0; i <= n; ++i) {
        int temp = cnt[i];
        while (temp > d) {
            answer += temp / d;
            temp = temp / d + temp % d;
        }
    }

    cout << answer << '\n';

    return 0;
}