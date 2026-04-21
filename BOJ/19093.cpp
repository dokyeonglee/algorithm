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

        int b = 1 << (31 - __builtin_clz(n));
        b >>= 1;

        string str = "1";
        while (b > 0) {
            str = '(' + str;
            str += "*(1+1)";
            if (n & b) {
                str += "+1";
            }
            str += ')';
            b >>= 1;
        }

        cout << str << '\n';
    }

    return 0;
}