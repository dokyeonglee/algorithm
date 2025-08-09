#include <iostream>
#include <vector>

using namespace std;

struct Sowing {
    int r1, c1, r2, c2;
};

void apply_sowing(vector<vector<int>>& diff, const Sowing& sowing, int n) {
    const auto& [r1, c1, r2, c2] = sowing;
    ++diff[r1][c1];
    --diff[r1][c2 + 1];
    --diff[r2 + 1][c1];
    ++diff[r2 + 1][c2 + 1];
} 

vector<vector<int>> build_future_garden(const vector<vector<int>>& garden, const vector<Sowing>& sowings, const int n) {
    vector<vector<int>> diff(n + 2, vector<int>(n + 2));
    for (const auto& sowing : sowings) {
        apply_sowing(diff, sowing, n);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            diff[i][j] += diff[i][j - 1] + diff[i - 1][j] - diff[i - 1][j - 1];
        }
    }

    vector<vector<int>> future_garden(garden);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            future_garden[i][j] += diff[i][j];
            future_garden[i][j] %= 2;
        }
    }

    return future_garden;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> garden(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> garden[i][j];
        }
    }

    int m;
    cin >> m;

    vector<Sowing> sowings(m);
    for (auto& sowing : sowings) {
        cin >> sowing.c1 >> sowing.r1 >> sowing.c2 >> sowing.r2;
    }

    auto future_garden = build_future_garden(garden, sowings, n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << future_garden[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}