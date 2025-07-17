#include <iostream>

using namespace std;
using ll = long long;

constexpr int MAX_ASK_QUERIES = 41;

ll ask_query(ll t) {
    cout << "? " << t << endl;
    ll position_in_lap;
    cin >> position_in_lap;
    return position_in_lap;
}

void answer_query(ll length) {
    cout << "! " << length << endl;
}

int main(){
    ll t = 1;

    for (int i = 0; i < MAX_ASK_QUERIES; ++i) {
        ll position_in_lap = ask_query(t);

        if (t == position_in_lap) {
            t <<= 1;
        } else {
            answer_query(t - position_in_lap);
            return 0;
        }
    }

    return 0;
}