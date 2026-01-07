#include <iostream>

using namespace std;

int main() {
    long long n;
    int a, b, c, d, e, f;

    cin >> n;
    cin >> a >> b >> c >> d >> e >> f;

    long long answer = 0;
    for (long long i = n - n % f + 1; i <= n; ++i) {
        if (i % a == 0) {
            answer += i;
        }
        if (i % b == 0) {
            answer %= i;
        }
        if (i % c == 0) {
            answer &= i;
        }
        if (i % d == 0) {
            answer ^= i;
        }
        if (i % e == 0) {
            answer |= i;
        }
        if (i % f == 0) {
            answer >>= i;
        }
    }
    
    cout << answer << '\n';

    return 0;
}