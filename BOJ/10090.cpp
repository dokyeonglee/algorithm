#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll query(const vector<int>& fenwick_tree, int idx) {
    ll result = 0;
    while (idx > 0) {
        result += fenwick_tree[idx];
        idx &= (idx - 1);
    }
    return result;
}

void update(vector<int>& fenwick_tree, int idx, int value = 1) {
    while (idx < fenwick_tree.size()) {
        fenwick_tree[idx] += value;
        idx += (idx & -idx);
    }
}

ll count_inversions(const vector<int>& arr) {
    const int n = arr.size();
    vector<int> fenwick_tree(n + 1);

    ll inversions = 0;

    for (int i = 0; i < n; ++i) {
        inversions += i - query(fenwick_tree, arr[i]);
        update(fenwick_tree, arr[i]);
    }

    return inversions;
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

    cout << count_inversions(arr) << '\n';

    return 0;
}