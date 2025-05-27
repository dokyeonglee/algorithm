#include <iostream>
#include <vector>

using namespace std;

struct Partition {
    long long max_net_score = 0;
    int round_count = 1;
};

Partition calculate_best_partition(const vector<int>& ability) {

    const int n = ability.size();
    long long suffix_sum = 0;
    Partition best_partition;

    for (int i = n - 1; i >= 0; --i) {
        if (suffix_sum > 0) {
            ++best_partition.round_count;
            best_partition.max_net_score += suffix_sum;
        }
        best_partition.max_net_score += ability[i];
        suffix_sum += ability[i];
    }

    return best_partition;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> team(n);

    for (int& t : team) {
        cin >> t;
    }

    vector<int> ability(n);

    for (int i = 0; i < n; ++i) {
        cin >> ability[i];
    }

    for (int i = 0; i < n; ++i) {
        if (team[i] == 0) {
            ability[i] = -ability[i];
        }
    }

    Partition best_partition = calculate_best_partition(ability);
    cout << best_partition.round_count << ' ' << best_partition.max_net_score << '\n';

    return 0;

}