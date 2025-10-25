#include <iostream>
#include <vector>

using namespace std;

int count_picture(const vector<string>& gallery, int r, int c, bool vertical) {
    int pictures = 0;
    int cnt = 0;
    char ch;

    while (r < gallery.size() && c < gallery[0].size()) {
        if (cnt == 0) {
            ch = gallery[r][c];
        }

        if (gallery[r][c] != gallery[r - !vertical][c - vertical]) {
            if (gallery[r][c] == ch) {
                ++cnt;
            } else {
                pictures += cnt / 2;
                ch = gallery[r][c];
                cnt = 1;
            }
        } else {
            pictures += cnt / 2;
            cnt = 0;
        }

        r += vertical;
        c += !vertical;
    }

    return pictures;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> gallery(n);
    for (int i = 0; i < n; ++i) {
        cin >> gallery[i];
    }

    int pictures = 0;

    for (int i = 1; i < n; ++i) {
        pictures += count_picture(gallery, i, 1, false);
    }

    for (int i = 1; i < m; ++i) {
        pictures += count_picture(gallery, 1, i, true);
    }

    cout << pictures << '\n';

    return 0;
}