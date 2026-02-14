#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long k;
    cin >> k;

    long long temp = abs(k);
    long long answer = 1;
    for (int i = 2; i * i <= temp; ++i) {
        int cnt = 1;
        while (temp % i == 0) {
            cnt += 2;
            temp /= i;
        }
        answer *= cnt;
    }

    if (temp > 1) {
        answer *= 3;
    }

    ++answer;

    cout << answer << ' ' << 2 * k * answer << '\n';

    return 0;
}