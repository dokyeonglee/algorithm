#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string str;
        cin >> str;

        if (str.size() == 1) {
            cout << 1 << '\n';
            continue;
        }
        
        int idx = 1;
        int prev_length = 1;
        int substr_count = 1;

        while (idx < str.size() - 1) {
            ++substr_count;

            if (prev_length == 1 && str[idx] == str[idx - 1]) {
                prev_length = 2;
            } else {
                prev_length = 1;
            }

            idx += prev_length;
        }

        if (idx < str.size() && !(prev_length == 1 && str[idx] == str[idx - 1])) {
            ++substr_count;
        }

        cout << substr_count << '\n';
    }

    return 0;
}