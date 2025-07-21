#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

ll simulate_shootings(const vector<int>& targets, const int max_shots, ll ability) {
    ll score = 0;
    auto it = targets.begin();

    for (int i = 0; i < max_shots; ++i) {
        while (it != targets.end() && *it <= ability) {
            ++it;
        }

        if (it == targets.begin()) {
            break;
        }

        int gain = *(it - 1);
        ability += gain;
        score += gain;
    }

    return score;
}

int find_min_initial_ability(vector<int>& targets, const int max_shots, const ll required_score) {
    sort(targets.begin(), targets.end());

    int left = targets.front();
    int right = targets.back();
    int min_ability = right;

    while (left <= right) {
        int mid = (left + right) / 2;
        ll score = simulate_shootings(targets, max_shots, mid);

        if (score >= required_score) {
            min_ability = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return min_ability;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, max_shots;
    ll required_score;
    cin >> n >> max_shots >> required_score;

    vector<int> targets(n);
    for (int& target : targets) {
        cin >> target;
    }

    cout << find_min_initial_ability(targets, max_shots, required_score) << '\n';

    return 0;
}