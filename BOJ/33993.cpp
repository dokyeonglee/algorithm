#include <iostream>
#include <vector>

using namespace std;

struct Seat {
    int satisfaction = 0;
    pair<int, int> position;
};

int count_friends_in_window(const vector<vector<int>>& prefix_sum, const int seat_x, const int seat_y, const int window_size) {
    const int half = window_size / 2;
    const int bottom_right_x = seat_x + half;
    const int bottom_right_y = seat_y + half;
    const int top_left_x = max(1, seat_x - half);
    const int top_left_y = max(1, seat_y - half);
    return prefix_sum[bottom_right_x][bottom_right_y] - prefix_sum[bottom_right_x][top_left_y - 1]
        - prefix_sum[top_left_x - 1][bottom_right_y] + prefix_sum[top_left_x - 1][top_left_y - 1];
}

const Seat find_best_seat(const vector<vector<bool>>& is_occupied, const vector<vector<int>>& prefix_sum, const int window_size) {

    const int r = prefix_sum.size() - 1;
    const int c = prefix_sum[0].size() - 1;
    const int half = window_size / 2;

    Seat best_seat;

    for (int i = half + 1; i <= r; ++i) {
        for (int j = half + 1; j <= c; ++j) {
            if (!is_occupied[i - half][j - half]) {
                int satisfaction = count_friends_in_window(prefix_sum, i - half, j - half, window_size);
                if (best_seat.satisfaction < satisfaction) {
                    best_seat.satisfaction = satisfaction;
                    best_seat.position = {i - half, j - half};
                }
            }
        }
    }

    return best_seat;
}

void compute_prefix_sum(const vector<vector<bool>>& is_occupied, vector<vector<int>>& prefix_sum) {
    for (int i = 1; i < prefix_sum.size(); ++i) {
        for (int j = 1; j < prefix_sum[0].size(); ++j) {
            prefix_sum[i][j] = is_occupied[i][j] + prefix_sum[i][j - 1] + prefix_sum[i - 1][j] - prefix_sum[i - 1][j - 1];
        }
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, r, c, window_size;
    cin >> n >> r >> c >> window_size;

    const int half = window_size / 2;

    vector<vector<bool>> is_occupied(r + half + 1, vector<bool>(c + half + 1));

    for (int i = 0; i < n; ++i) {
        int bottom_right_x, bottom_right_y;
        cin >> bottom_right_x >> bottom_right_y;
        is_occupied[bottom_right_x][bottom_right_y] = true;
    }

    vector<vector<int>> prefix_sum(r + half + 1, vector<int>(c + half + 1));
    compute_prefix_sum(is_occupied, prefix_sum);

    const auto best_seat = find_best_seat(is_occupied, prefix_sum, window_size);
    cout << best_seat.satisfaction << '\n';
    cout << best_seat.position.first << ' ' << best_seat.position.second << '\n';

    return 0;
}