#include <iostream>

using namespace std;

int largest_prime_leq(const int n) {
    if (n == 2) {
        return n;
    }

    for (int i = n - 1 + n % 2; i >= 3; i -= 2) {
        bool is_prime = true;
        for (int j = 3; j * j <= i; j += 2) {
            if (i % j == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            return i;
        }
    }
}

int main() {
    int n;
    cin >> n;

    cout << largest_prime_leq(n) << '\n';

    return 0;
}