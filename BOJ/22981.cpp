#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

long long _compute_min_time(const vector<int>& speeds, const long long number_of_boxes) {

    const int n = speeds.size();
    long long max_team_speed_sum = 0;
    long long min_time = LLONG_MAX;

    for (int i = 0; i < n - 1; ++i) {
        long long team1_speed = (long long)speeds[0] * (i + 1);
        long long team2_speed = (long long)speeds[i + 1] * (n - 1 - i);
        long long team_speed_sum = team1_speed + team2_speed;
        max_team_speed_sum = max(max_team_speed_sum, team_speed_sum);
    }

    if (max_team_speed_sum > 0) {
        min_time = (number_of_boxes + max_team_speed_sum - 1) / max_team_speed_sum;
    }

    return min_time;
}

long long compute_min_time(vector<int>& speeds, const long long number_of_boxes) {
    sort(speeds.begin(), speeds.end());
    long long min_time = _compute_min_time(speeds, number_of_boxes);
    return min_time;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long number_of_boxes;
    cin >> n >> number_of_boxes;

    vector<int> speeds(n);
    for (auto& s : speeds) {
        cin >> s;
    }

    cout << compute_min_time(speeds, number_of_boxes) << '\n';

    return 0;
}