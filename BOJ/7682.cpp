#include <iostream>
#include <vector>

using namespace std;

constexpr int TOTAL_CELLS = 9;
constexpr int bingo_lines[][3] = {
    {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
    {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, 
    {0, 4, 8}, {2, 4, 6}
};

pair<int, int> count_x_o(const string& tic_tac_toe) {
    int x_count = 0;
    int o_count = 0;

    for (const char cell : tic_tac_toe) {
        if (cell == 'X') {
            ++x_count;
        } else if (cell == 'O') {
            ++o_count;
        }
    }

    return {x_count, o_count};
}

pair<int, int> count_bingos(const string& tic_tac_toe) {
    int x_bingo = 0;
    int o_bingo = 0;

    for (const auto& [i, j, k] : bingo_lines) {
        if (tic_tac_toe[i] == tic_tac_toe[j] && tic_tac_toe[i] == tic_tac_toe[k]) {
            if (tic_tac_toe[i] == 'X') {
                ++x_bingo;
            } else if (tic_tac_toe[i] == 'O') {
                ++o_bingo;
            }
        }
    }

    return {x_bingo, o_bingo};
}

bool is_valid_state(const string& tic_tac_toe) {
    const auto [x_count, o_count] = count_x_o(tic_tac_toe);

    if (o_count > x_count || o_count + 1 < x_count) {
        return false;
    }

    const auto [x_bingo, o_bingo] = count_bingos(tic_tac_toe);

    if (x_bingo > 0 && o_bingo > 0) {
        return false;
    }

    if (x_bingo > 0) {
        return x_count == o_count + 1;
    }

    if (o_bingo > 0) {
        return x_count == o_count;
    }

    return (x_count + o_count) == TOTAL_CELLS;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (1) {
        string tic_tac_toe;
        cin >> tic_tac_toe;

        if (tic_tac_toe == "end") {
            break;
        }

        if (is_valid_state(tic_tac_toe)) {
            cout << "valid\n";
        } else {
            cout << "invalid\n";
        }
    }

    return 0;
}