#include <iostream>
#include <vector>

using namespace std;

const vector<vector<vector<int>>> transformations = {
{
{1, 0, 0},
{0, 0, -1},
{0, 1, 0}
},

{
{0, 0, 1},
{0, 1, 0},
{-1, 0, 0}
},

{
{0, -1, 0},
{1, 0, 0},
{0, 0, 1}
},

{
{1, 0, 0},
{0, -1, 0},
{0, 0, -1}
},

{
{-1, 0, 0},
{0, 1, 0},
{0, 0, -1}
},

{
{-1, 0, 0},
{0, -1, 0},
{0, 0, 1}
},

{
{1, 0, 0},
{0, 1, 0},
{0, 0, -1}
},

{
{-1, 0, 0},
{0, 1, 0},
{0, 0, 1}
},

{
{1, 0, 0},
{0, -1, 0},
{0, 0, 1}
}
};

vector<vector<int>> mat_mul(const vector<vector<int>>& a, const vector<vector<int>>& b, bool transpose = false) {
    vector<vector<int>> result(a.size(), vector<int>(b[0].size()));

    if (transpose) {
        for (int k = 0; k < a[0].size(); ++k) {
            for (int i = 0; i < a.size(); ++i) {
                for (int j = 0; j < b[0].size(); ++j) {
                    result[i][j] += a[i][k] * b[j][k];
                }
            }
        }
    } else {
        for (int k = 0; k < a[0].size(); ++k) {
            for (int i = 0; i < a.size(); ++i) {
                for (int j = 0; j < b[0].size(); ++j) {
                    result[i][j] += a[i][k] * b[k][j];
                }
            }
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<vector<int>>> psum(n + 1);
    psum[0] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

    for (int i = 1; i <= n; ++i) {
        string str;
        cin >> str;

        int idx;
        if (str == "X") {
            idx = 0;
        } else if (str == "Y") {
            idx = 1;
        } else if (str == "Z") {
            idx = 2;
        } else if (str == "XX") {
            idx = 3;
        } else if (str == "YY") {
            idx = 4;
        } else if (str == "ZZ") {
            idx = 5;
        } else if (str == "XY" || str == "YX") {
            idx = 6;
        } else if (str == "YZ" || str == "ZY") {
            idx = 7;
        } else if (str == "XZ" || str == "ZX") {
            idx = 8;
        }

        psum[i] = mat_mul(transformations[idx], psum[i - 1]);
    }

    int q;
    cin >> q;

    while (q--) {
        int l, r;
        cin >> l >> r;

        auto answer = mat_mul(psum[r], psum[l - 1], true);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << answer[j][i] << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}