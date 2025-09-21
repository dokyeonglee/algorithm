#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
using ll = long long;

ll equalize_prisoners(vector<int>& rooms) {
    const int n = rooms.size();
    const ll total_prisoners = accumulate(rooms.begin(), rooms.end(), 0ll);
    const ll prisoners_per_room = total_prisoners / n;

    ll moving_prisoners = 0;
    ll total_moves = 0;

    for (int round = 0; round < 2; ++round) {
        for (int i = 0; i < n; ++i) {
            total_moves += moving_prisoners;

            const ll needed = prisoners_per_room - rooms[i];
            if (needed > 0) {
                const ll take = min(needed, moving_prisoners);
                rooms[i] += take;
                moving_prisoners -= take;
            } else {
                rooms[i] += needed;
                moving_prisoners -= needed;
            }
        }
    }

    return total_moves;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> rooms(n);
    for (int i = 0; i < n; ++i) {
        cin >> rooms[i];
    }

    const ll total_moves = equalize_prisoners(rooms);
    cout << total_moves << '\n';

    return 0;
}