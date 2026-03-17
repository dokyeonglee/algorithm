#include <iostream>
#include <queue>

using namespace std;
using ll = long long;

int main() {
    ll b, k;
    cin >> b >> k;

    priority_queue<ll> pq;
    for (int i = 1; i < b; ++i) {
        pq.push(-i);
    }

    for (int i = 0; i < k; ++i) {
        ll x = -pq.top();
        pq.pop();
        cout << x << '\n';
        for (int j = 2; j <= 54; ++j) {
            ll y = j * x;
            int cnt = 0;
            while (y) {
                y /= b;
                ++cnt;
            }
            if (cnt == j) {
                pq.push(-j * x);
            }   
        }
    }

    return 0;
}