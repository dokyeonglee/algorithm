#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

ll find_meeting_position(const pair<ll, ll> current, const pair<ll, ll> new_friend) {
    ll position = current.first;

    if (current.first < new_friend.first) {
        ll diff = new_friend.first - position;
        ll move_count = (diff + current.second - 1) / current.second;
        position +=  current.second * move_count;
    }

    for (int i = 0; i < new_friend.second; ++i) {
        if ((position - new_friend.first) % new_friend.second == 0){
            return position; 
        }
        position += current.second;
    }

    return -1;
}

ll find_meeting_position(const vector<pair<ll, ll>>& friends) {
    pair<ll, ll> current = friends[0];

    for (int i = 1; i < friends.size(); ++i) {
        ll next_position = find_meeting_position(current, friends[i]);

        if (next_position == -1) {
            return -1;
        }

        current = {next_position, lcm(current.second, friends[i].second)};
    }

    return current.first;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<ll, ll>> friends(n);
    for (auto& fr : friends) {
        cin >> fr.first >> fr.second;
    }

    cout << find_meeting_position(friends) << '\n';

    return 0;
}