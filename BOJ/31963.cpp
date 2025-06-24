#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int calculate_doubling_delta(const int current, const int previous) {
    if (current < previous) {
        return 32 - __builtin_clz((previous + current - 1) / current - 1);
    }
    return __builtin_clz(current / previous) - 31;
}

ll count_min_doubling(const vector<int>& arr) {
    ll total_doublings = 0;
    int current_doublings = 0;

    for (int i = 1; i < arr.size(); ++i) {
        current_doublings += calculate_doubling_delta(arr[i], arr[i - 1]);

        if (current_doublings > 0) {
            total_doublings += current_doublings;
        } else {
            current_doublings = 0;
        }
    }

    return total_doublings;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto& a : arr) {
      cin >> a;
    }

    cout << count_min_doubling(arr);  

    return 0;
}