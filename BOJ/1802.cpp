#include <iostream>
#include <vector>

using namespace std;

bool possible(const string& str, const int r) {
    if (r == 0) {
        return true;
    }

    int idx = 0;
    while (idx != r - idx) {
        if (str[idx] == str[r - idx]) {
            return false;
        }
        ++idx;
    }

    return possible(str, r / 2 - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string str;
        cin >> str;

        if (possible(str, str.size() - 1)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}