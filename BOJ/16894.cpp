#include <iostream>

using namespace std;

int number_of_prime_factors(long long n) {
    int cnt = 0;
    for (long long i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            ++cnt;
            n /= i;
        }
    }

    if (n > 1) {
        ++cnt;
    }

    return cnt;
}

int main() {
    long long n;
    cin >> n;

    if (number_of_prime_factors(n) != 2) {
        cout << "koosaga\n";
    } else {
        cout << "cubelover\n";
    }

    return 0;
}