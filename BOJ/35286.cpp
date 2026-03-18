#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        if (n % 2) {
            cout << "H\n";
        } else {
            cout << "S\n";
        }
    }

    return 0;
}