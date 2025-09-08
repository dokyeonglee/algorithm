#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll count_grampan(const string& str) {
    ll grampans = 0;
    int a_count = 0;

    char expect = 'A';

    for (const char c : str) {
        if (c == expect + 1) {
            expect = c;
        } else if (c != expect) {
            a_count = 0;
            expect = 'A';
        }

        if (c == 'A') {
            ++a_count;
        }
        
        if (c == 'Z') {
            grampans += a_count;
        }
    }

    return grampans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;

    cout << count_grampan(str) << '\n';

    return 0;
}