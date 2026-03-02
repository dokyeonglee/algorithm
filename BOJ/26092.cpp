#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ll a, b;
    cin >> a >> b;

    vector<ll> a_parents{a};
    for (ll i = 2; i * i <= a; ++i) {
        while (a % i == 0) {
            a /= i;
            a_parents.push_back(a);
        }
    }

    if (a > 1) {
        a_parents.push_back(a);
    }

    vector<ll> b_parents{b};
    for (ll i = 2; i * i <= b; ++i) {
        while (b % i == 0) {
            b /= i;
            b_parents.push_back(b);
        }
    }

    if (b > 1) {
        b_parents.push_back(b);
    }

    a_parents.push_back(1);
    b_parents.push_back(1);

    int idx = 0;
    for (int i = 0; i < a_parents.size(); ++i) {
        while (idx < b_parents.size() && b_parents[idx] > a_parents[i]) {
            ++idx;
        }
        if (idx < b_parents.size() && a_parents[i] == b_parents[idx]) {
            cout << a_parents[i];
            return 0;
        }
    }

    return 0;
}