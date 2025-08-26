#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

constexpr ll MAX_TIME = 1e18;

ll count_balloons(const ll time, const int x, const int y, const int z) {
    return time / x + time / y + time / z;
}

ll find_last_time(const int n, const int x, const int y, const int z) {
    ll left = 1;
    ll right = MAX_TIME;
    ll last_time = MAX_TIME;

    while (left <= right) {
        ll mid = (left + right) / 2;
        ll balloons = count_balloons(mid, x, y, z);

        if (balloons >= n) {
            last_time = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return last_time;
}

char find_winner(const int n, const int x, const int y, const int z) {
    
    ll last_time = find_last_time(n, x, y, z);
    ll balloons = count_balloons(last_time, x, y, z);

    string candidates;
    if (last_time % z == 0) {
        candidates += 'C';
    }
    if (last_time % y == 0) {
        candidates += 'B';
    }
    if (last_time % x == 0) {
        candidates += 'A';
    }

    return candidates[balloons - n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x, y, z;
    cin >> n >> x >> y >> z;

    char winner = find_winner(n, x, y, z);
    cout << winner << " win\n";

    return 0;
}