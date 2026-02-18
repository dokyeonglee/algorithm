#include <iostream>

using namespace std;

bool solve(int a, int b) {
    if (a % b == 0) {
        return true;
    }
    return a / b != 1 || !solve(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (1) {
        int a, b;
        cin >> a >> b;

        if (a == 0 && b == 0) {
            break;
        }

        if (a < b) {
            swap(a, b);
        }

        if (solve(a, b)) {
            cout << "A wins\n";
        } else {
            cout << "B wins\n";
        }
    }

    return 0;
}