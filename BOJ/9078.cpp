#include <iostream>
#include <vector>

using namespace std;

int count_inversions(const vector<int>& arr) {
    const int n = arr.size();
    int count = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j]) {
                ++count;
            }
        }
    }

    return count;
}

bool is_sortable(const vector<int>& arr) {
    return count_inversions(arr) % 2 == 0;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int& a : arr) {
            cin >> a;
        }

        if (is_sortable(arr)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}