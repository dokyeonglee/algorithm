#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int w, h;
    cin >> w >> h;

    int n;
    cin >> n;

    vector<double> x(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    const double base = 1.0 * w * h / 2.0;

    vector<double> psum(n + 1);
    for (int i = 1; i <= n; ++i) {
        const double y = w / (x[i] / h - (x[i - 1] - w) / h);
        psum[i] = psum[i - 1] + (base - w * y / 2.0);
    }

    int q;
    cin >> q;

    

    cout.fixed;
    cout.precision(10);
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << base + psum[r] - psum[l] << '\n';
    }

    return 0;
}