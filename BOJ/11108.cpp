#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

struct TVShow {
    int start;
    int duration;
    int preference;

    bool operator<(const TVShow& other) const {
        return (start + duration) < (other.start + other.duration);
    }    
};

ll calculate_max_preference(vector<TVShow>& shows) {
    sort(shows.begin(), shows.end());

    int max_end_time = shows.back().start + shows.back().duration;

    vector<ll> dp(max_end_time + 1);
    int current_time = 0;

    for (const auto& [start, duration, preference] : shows) {
        int end_time = start + duration;

        while (current_time < end_time) {
            dp[current_time + 1] = max(dp[current_time + 1], dp[current_time]);
            ++current_time;
        }

        dp[end_time] = max(dp[end_time], dp[start] + preference);
    }

    return dp[max_end_time];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<TVShow> shows(n);
        for (auto& show : shows) {
            cin >> show.start >> show.duration >> show.preference;
        }

        cout << calculate_max_preference(shows) << '\n';
    }

    return 0;
}