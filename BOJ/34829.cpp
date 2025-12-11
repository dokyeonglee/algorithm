#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mex(const vector<int>& arr) {
    int result = 0;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] != result) {
            return i;
        }
        ++result;
    }
    return result;
}

int solve(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    return arr[arr.size() / 2] + mex(arr);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int& a : arr) {
        cin >> a;
    }

    vector<int> b1{*min_element(arr.begin(), arr.end()), *max_element(arr.begin(), arr.end())};
    vector<int> b2(arr);

    cout << max(solve(b1), solve(b2));

    return 0;
}