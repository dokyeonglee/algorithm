#include <iostream>

using namespace std;

void solve(const int n) {
    if (n <= 2) {
        cout << -1;
    } else if (n == 3) {
        cout << "2 5 29";
    }else if (n == 4) {
        cout << "2 2 3 17";
    } else if (n == 6) {
        cout << "2 2 3 3 3 5";
    } else {
        int sz;
        if (n % 2 == 0) {
            cout << "2 2 2 2 2 2 ";
            sz = (n - 6) / 2;
        } else {
            cout << "2 2 2 ";
            sz = (n - 3) / 2;
        }
        for (int i = 0; i < sz; ++i) {
            cout << "3 3 ";
        }
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    solve(n);

    return 0;
}