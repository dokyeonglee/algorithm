#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calculate_max_adjacent_difference(const vector<int>& arr) {
    int max_adjacent_difference = 0;
    for (int i = 1; i < arr.size(); ++i) {
        max_adjacent_difference = max(max_adjacent_difference, abs(arr[i] - arr[i - 1]));
    }
    return max_adjacent_difference;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> h(n);
    vector<int> inverse_h(n);

    for (int i = 0; i < n; ++i) {
        cin >> h[i];
        inverse_h[h[i] - 1] = i;
    }

    int ponix_numerator = calculate_max_adjacent_difference(h);
    int chanu_denominator = calculate_max_adjacent_difference(inverse_h);

    cout << ponix_numerator << '/' << 1 << '\n';
    cout << 1 << '/' << chanu_denominator << '\n';

    return 0;
}