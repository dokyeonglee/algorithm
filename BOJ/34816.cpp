#include <iostream>

using namespace std;

constexpr char toggle = ('0' ^ '1');

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    string str;
    cin >> str;

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int idx;
            cin >> idx;
            str[idx - 1] ^= toggle;
        } else if (type == 2) {
            int x, y;
            cin >> x >> y;

            bool check = true;
            if (y - x < 3) {
                if (x == y) {
                    check = false;
                } else {
                    check = (str[x - 1] == str[x] || str[y - 2] == str[y - 1]);
                }
            }

            if (check) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}