#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll calculate_min_delivery_cost(const vector<int>& fleas) {
    ll delivery_cost = 0;
    int balance = 0;

    for (const int flea : fleas) {
        balance += flea;
        delivery_cost += abs(balance);
    }

    return delivery_cost;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> fleas(n);

    for (int& flea : fleas) {
        cin >> flea;
    }

    cout << calculate_min_delivery_cost(fleas);

    return 0;
}