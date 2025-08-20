#include <iostream>

using namespace std;

string build_headache_string(const string& str, const int n) {
    int w_count = 0;
    string headache_string(str.size(), 'w');

    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == 'w') {
            ++w_count;
        } else if (str[i] == 'h') {
            headache_string[i - min(n, w_count)] = 'h';
        } else {
            headache_string[i] = str[i];
            w_count = 0;
        }
    }

    return headache_string;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int l, n;
    cin >> l >> n;

    string str;
    cin >> str;

    cout << build_headache_string(str, n) << '\n';

    return 0;
}