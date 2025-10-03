#include <iostream>
#include <vector>

using namespace std;

vector<int> build_sequence(const int n) {
    vector<int> result;
    int i = 2;
    int square_root = 3;

    while (i <= n) {
        int sum = 2 * i + 1;

        if (sum == square_root * square_root) {
            result.push_back(i);
            result.push_back(i - 1);
            i += 2;
        } else {
            result.push_back(i - 1);
            ++i;
        }

        if (sum >= square_root * square_root) {
            square_root += 2;
        }
    }

    if (i == n + 1) {
        result.push_back(n);
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        auto sequence = build_sequence(n);
        for (const int x : sequence) {
            cout << x << ' ';
        }
        cout << '\n';
    }

    return 0;
}