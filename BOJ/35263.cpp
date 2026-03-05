#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<bool> is_prime(1000, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i < is_prime.size(); ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j < is_prime.size(); j += i) {
                is_prime[j] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = 2; i < is_prime.size(); ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }

    int n, m;
    cin >> n >> m;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    vector<int> exploded(n + 2);
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        ++exploded[l];
        --exploded[r + 1];
    }

    for (int i = 1; i <= n; ++i) {
        exploded[i] += exploded[i - 1];
    }

    double answer = 0;
    for (int i = 1; i <= n; ++i) {
        if (exploded[i]) {
            int cnt = 0;
            double sum = 0;
            for (int j = 0; primes[j] * primes[j] <= arr[i]; ++j) {
                if (arr[i] % primes[j] == 0) {
                    ++cnt;
                    sum += primes[j];
                    while (arr[i] % primes[j] == 0) {
                        arr[i] /= primes[j];
                    }
                }
            }
            if (arr[i] > 1) {
                ++cnt;
                sum += arr[i];
            }
            answer += sum / cnt;
        } else {
            answer += arr[i];
        }
    }

    cout << fixed;
    cout.precision(10);
    cout << answer << '\n';

    return 0;
}