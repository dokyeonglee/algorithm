#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int min_lines_to_cover(vector<pair<int, int>>& lines, const int s, const int e) {
    sort(lines.begin(), lines.end());

    int covered_until = s;
    int used_lines = 0;
    int idx = 0;

    while (covered_until < e) {
        int temp = covered_until;
        while (idx < lines.size() && lines[idx].first <= covered_until) {
            temp = max(temp, lines[idx++].second);
        }

        if (temp == covered_until) {
            return 0;
        }

        ++used_lines;
        covered_until = temp;
    }

    return used_lines;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;

    vector<pair<int, int>> lines;
    while (1) {
        int l, r;
        cin >> l >> r;
        if (l == 0 && r == 0) {
            break;
        }
        lines.emplace_back(l, r);
    }

    cout << min_lines_to_cover(lines, 0, m) << '\n';

    return 0;
}