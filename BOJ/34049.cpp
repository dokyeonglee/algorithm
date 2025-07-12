#include <iostream>
#include <vector>

using namespace std;

int max_valid_segments(const vector<int>& arr) {
    int valid_segments = 0;
    long long current_sum = 0;

    for (int i = arr.size() - 1; i >= 0; --i) {
        current_sum += arr[i];

        if (current_sum >= 0) {
            ++valid_segments;
            current_sum = 0;
        }
    }

    if (current_sum < 0) {
        return -1;
    }

    return valid_segments;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int& a : arr) {
        cin >> a;
    }

    cout << max_valid_segments(arr) << '\n';

    return 0;
}