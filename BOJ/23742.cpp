#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

ll calculate_max_total_score(vector<int>& players) {
    ll max_total_score = 0;
    ll prefix_sum = 0;

    sort(players.rbegin(), players.rend());

    for (int i = 0; i < players.size(); i++) {
        prefix_sum += players[i];
        max_total_score = max(max_total_score + players[i], prefix_sum * (i + 1));
    }

    return max_total_score;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> players(n);
    for (auto& a : players) {
        cin >> a;
    }

    cout << calculate_max_total_score(players) << '\n';

    return 0;
}