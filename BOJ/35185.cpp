#include <iostream>
#include <vector>

using namespace std;

int flag_position(const string& str, int n, int start) {
    vector<bool> visited(n + 1);
    visited[start] = true;

    int idx = start;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == 'L') {
            idx = max(idx - 1, 1);
        } else if (str[i] == 'R') {
            idx = min(idx + 1, n);
        }
        if (i != str.size() - 1) {
            visited[idx] = true;
        }
    }

    if (visited[idx]) {
        return -1;
    }

    return idx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l;
    cin >> n >> l;

    string str;
    cin >> str;

    int start = 1;
    int position = flag_position(str, n, start);
    if (position == -1) {
        start = n;
        position = flag_position(str, n, start);
    }

    if (position != -1) {
        cout << "WIN\n";
        cout << start << ' ' << position << '\n';
    } else {
        cout << "DEFEAT\n";
    }

    return 0;
}