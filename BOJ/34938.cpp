#include <iostream>
#include <vector>

using namespace std;

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

int solve(const string& sequence) {
    pair<int, int> pos;
    int dir = 0;

    for (const char ch : sequence) {
        if (ch == 'U') {
            pos.first += dr[dir];
            pos.second += dc[dir];
        } else if (ch == 'L') {
            dir = (dir + 3) % 4;  
        } else if (ch == 'R') {
            dir = (dir + 1) % 4;
        }
    }

    if (pos.first == 0 && pos.second == 0) {
        return 0;
    }

    return dir == 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    string sequence;
    cin >> sequence;

    while (q--) {
        int i;
        char x;
        cin >> i >> x;

        sequence[i - 1] = x;
        cout << solve(sequence) << '\n';
    }

    return 0;
}