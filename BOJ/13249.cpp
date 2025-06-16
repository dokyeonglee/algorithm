#include <iostream>
#include <vector>

using namespace std;

double calculate_expected_collisions_count(const vector<int>& ball_positions, const int time_limit) {

    const int n = ball_positions.size();
    const double collision_probability = 0.25;
    double expected_count = 0.0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int distance = abs(ball_positions[i] - ball_positions[j]);
            if (distance <= 2 * time_limit) {
                ++expected_count;
            }
        }
    }

    expected_count *= collision_probability;

    return expected_count;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> ball_positions(n);
    for (int& position : ball_positions) {
        cin >> position;
    }

    int time_limit;
    cin >> time_limit;

    cout << fixed;
    cout.precision(10);
    cout << calculate_expected_collisions_count(ball_positions, time_limit) << '\n';

    return 0;
}