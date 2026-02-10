#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, a;
        cin >> n >> a;

        if (n == 2 || n % 2 == 1) {
            cout << "O\n";
        } else {
            cout << "I\n";
        }
    }

    return 0;
}