#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

struct Query {
    int type;
    int i, j, k;
    int x;
};

ll prefix_sum(const vector<ll>& fenwick_tree, int idx) {
    ll result = 0;
    while (idx > 0) {
        result += fenwick_tree[idx];
        idx -= (idx & -idx);
    }
    return result;
}

void update(vector<ll>& fenwick_tree, int idx, int value) {
    while (idx < fenwick_tree.size()) {
        fenwick_tree[idx] += value;
        idx += (idx & -idx);
    }
}

vector<ll> process_queries(const vector<int>& arr, const vector<Query>& queries) {
    const int n = arr.size() - 1;
    vector<ll> fenwick_tree(n + 2);

    for (int i = 1; i <= n; ++i) {
        update(fenwick_tree, i, arr[i] - arr[i - 1]);
    }

    vector<ll> results;
    for (auto& q : queries) {
        if (q.type == 1) {
            update(fenwick_tree, q.i, q.k);
            update(fenwick_tree, q.j + 1, -q.k);
        } else {
            results.push_back(prefix_sum(fenwick_tree, q.x));
        }
    }

    return results;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> arr(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    
    int q;
    cin >> q;

    vector<Query> queries(q);
    for (auto& q : queries) {
        cin >> q.type;
        if (q.type == 1) {
            cin >> q.i >> q.j >> q.k;
        } else {
            cin >> q.x;
        }
    }

    vector<ll> results = process_queries(arr, queries);
    for (const ll& x : results) {
        cout << x << '\n';
    }

    return 0;
}