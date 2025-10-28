#include <iostream>
#include <vector>

using namespace std;

constexpr int MAX_N = 431;

int prime_exponent_in_factorial(const int n, const int prime) {
    int result = 0;
    int p = prime;
    while (p <= n) {
        result += n / p;
        p *= prime;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<bool> is_prime(MAX_N + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;

    for (int i = 2; i * i <= MAX_N; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAX_N; j += i) {
                is_prime[j] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = 2; i <= MAX_N; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }

    int n, k;

    while(cin >> n >> k) {
        long long divisor_count = 1;
        for (const int prime : primes) {
            int prime_exponent = 
                prime_exponent_in_factorial(n, prime) 
                - prime_exponent_in_factorial(k, prime) 
                - prime_exponent_in_factorial(n - k, prime);
            divisor_count *= (prime_exponent + 1);
        }

        cout << divisor_count << '\n';
    }

    return 0;
}