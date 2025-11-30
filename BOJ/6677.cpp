#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> arr(256, vector<char>(256, '*'));

void init(vector<string>& picture) {
    picture.front().front() = '+';
    picture.front().back() = '+';
    picture.back().front() = '+';
    picture.back().back() = '+';

    for (int i = 1; i <= picture[0].size() - 2; ++i) {
        picture.front().at(i) = '-';
        picture.back().at(i) = '-';
    }
    for (int i = 1; i <= picture.size() - 2; ++i) {
        picture[i].front() = '|';
        picture[i].back() = '|';
    }
}

void point(vector<string>& picture) {
    int c, r;
    cin >> c >> r;

    if (r >= 1 && r < picture.size() - 1 && c >= 1 && c < picture[0].size() - 1) {
        picture[r][c] = arr[picture[r][c]]['o'];
    }
}

void text(vector<string>& picture) {
    int c, r;
    cin >> c >> r;

    string txt;
    cin >> txt;

    if (r >= picture.size() - 1) {
        return;
    }

    int idx = 0;
    int e = min(c + txt.size() - 1, picture[0].size() - 2);

    while (c <= e) {
        picture[r][c] = arr[picture[r][c]][txt[idx++]];
        ++c;
    }
}

void clear(vector<string>& picture) {
    int c1, r1, c2, r2;
    cin >> c1 >> r1 >> c2 >> r2;

    if (c1 > c2) {
        swap(c1, c2);
    }
    if (r1 > r2) {
        swap(r1, r2);
    }

    r1 = max(r1, 1);
    r2 = min(r2, (int)picture.size() - 2);
    c1 = max(c1, 1);
    c2 = min(c2, (int)picture[0].size() - 2);

    for (int i = r1; i <= r2; ++i) {
        for (int j = c1; j <= c2; ++j) {
            picture[i][j] = ' ';
        }
    }
}

void line(vector<string>& picture) {
    int c1, r1, c2, r2;
    cin >> c1 >> r1 >> c2 >> r2;

    int dr = r2 - r1;
    int dc = c2 - c1;
    char ch;

    if (dr == 0) {
        dc /= abs(dc);
        ch = '-';
    } else if (dc == 0) {
        dr /= abs(dr);
        ch = '|';
    } else {
        dr /= abs(dr);
        dc /= abs(dc);

        if ((dr == 1 && dc == 1) || (dr == -1 && dc == -1)) {
            ch = '\\';
        }
        if ((dr == -1 && dc == 1) || (dr == 1 && dc == -1)) {
            ch = '/';
        }
    }

    r2 += dr;
    c2 += dc;

    while(r1 != r2 || c1 != c2) {
        if (!(r1 >= 1 && r1 <= picture.size() - 2 && c1 >= 1 && c1 <= picture[0].size() - 2)) {
            continue;
        }
        picture[r1][c1] = arr[picture[r1][c1]][ch];
        r1 += dr;
        c1 += dc;
    }
}

void print(const vector<string>& picture) {
    for (const auto& row : picture) {
        cout << row << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 256; ++i) {
        arr[' '][i] = i;
        arr[i][i] = i;
    }

    arr['-']['|'] = '+';
    arr['|']['-'] = '+';
    arr['+']['-'] = '+';
    arr['+']['|'] = '+';

    arr['/']['\\'] = 'x';
    arr['\\']['/'] = 'x';
    arr['x']['/'] = 'x';
    arr['x']['\\'] = 'x';

    while (1) {
        int m, n;
        cin >> m >> n;

        if (n == 0) {
            break;
        }

        vector<string> picture(n + 2, string(m + 2, ' '));
        init(picture);

        string command;
        cin >> command;

        while (command != "PRINT") {
            if (command == "POINT") {
                point(picture);
            } else if (command == "TEXT") {
                text(picture);
            } else if (command == "CLEAR") {
                clear(picture);
            } else if (command == "LINE") {
                line(picture);
            }

            cin >> command;
        }

        print(picture);
        cout << '\n';
    }

    return 0;
}