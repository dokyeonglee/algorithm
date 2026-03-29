#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    vector<int> psum(n + 1);
    psum[1] = 1;

    for (int i = 2; i <= n; ++i) {
        psum[i] = psum[i - 1] + is_prime[i];
    }

    while (m--) {
        int a, b;
        cin >> a >> b;
        cout << psum[b] - psum[a - 1] << '\n';
    }

    return 0;
}