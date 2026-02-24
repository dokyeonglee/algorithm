#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        if (n % 2) {
            cout << n * (n - 1) * (n - 2) << '\n';
        } else if (n % 3) {
            cout << n * (n - 1) * (n - 3) << '\n';
        } else {
            cout << (n - 1) * (n - 2) * (n - 3) << '\n';
        }
    }

    return 0;
}