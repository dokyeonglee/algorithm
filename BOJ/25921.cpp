#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    long long answer = 2;
    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                if (is_prime[j]) {
                    answer += i;
                    is_prime[j] = false;
                }
            }
        }
    }

    for (int i = 3; i <= n; i += 2) {
        if (is_prime[i]) {
            answer += i;
        }
    }

    cout << answer;

    return 0;
}