#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
using namespace std;

constexpr int MAX_SIZE = 1e5;

ll compute_matryoshka_price(const int outer_size, vector<int>& size_count) {
    ll price = 0;

    for (int j = outer_size; size_count[j]; --j) {
        --size_count[j];
        price += outer_size;
    }

    return price;
}

void count_by_size(const vector<int>& doll_sizes, vector<int>& size_count) {
    for (const auto doll_size : doll_sizes) {
        ++size_count[doll_size];
    }
}

ll compute_total_profit(vector<int>& doll_sizes) {

    sort(doll_sizes.rbegin(), doll_sizes.rend());

    vector<int> size_count(MAX_SIZE + 1);
    count_by_size(doll_sizes, size_count);

    ll total_profit = 0;

    for (const auto doll_size : doll_sizes) {
        if (size_count[doll_size]) {
            total_profit += compute_matryoshka_price(doll_size, size_count);
        }
    }

    return total_profit;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> doll_sizes(n);
    
    for (auto& doll_size : doll_sizes) {
        cin >> doll_size;
    }

    cout << compute_total_profit(doll_sizes) << '\n';

    return 0;
}