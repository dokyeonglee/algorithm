#include <iostream>
#include <vector>

using namespace std;

constexpr int MAX_N = 10000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> phi(MAX_N + 1);
    for (int i = 1; i <= MAX_N; ++i) {
        phi[i] = i;
    }

    for (int i = 2; i <= MAX_N; ++i) {
        if (phi[i] == i) {
            for (int j = i; j <= MAX_N; j += i) {
                phi[j] = phi[j] * (i - 1) / i;
            }
        }
    }

    vector<int> psum(phi);
    psum[0] = 1;
    for (int i = 1; i <= MAX_N; ++i) {
        psum[i] += psum[i - 1];
    }

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        cout << psum[n] << '\n';
    }

    return 0;
}