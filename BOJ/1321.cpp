#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

struct Query {
    int type;
    int idx;
    int x;
};

ll prefix_sum(const vector<int>& fenwick_tree, int idx) {
    ll result = 0;
    while (idx > 0) {
        result += fenwick_tree[idx];
        idx &= (idx - 1);
    }
    return result;
}

void update(vector<int>& fenwick_tree, int idx, int value) {
    while (idx < fenwick_tree.size()) {
        fenwick_tree[idx] += value;
        idx += (idx & -idx);
    }
}

int find_unit_by_soldier_idx(const vector<int>& fenwick_tree, int soldier_idx) {
    int left = 1;
    int right = fenwick_tree.size() - 1;
    int unit = -1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (soldier_idx <= prefix_sum(fenwick_tree, mid)) {
            unit = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return unit;
}

vector<int> process_queries(const vector<int>& initial_unit_sizes, const vector<Query> queries) {
    vector<int> fenwick_tree(initial_unit_sizes.size());
    for (int i = 1; i < initial_unit_sizes.size(); ++i) {
        update(fenwick_tree, i, initial_unit_sizes[i]);
    }

    vector<int> results;
    for (const auto& q : queries) {
        if (q.type == 1) {
            update(fenwick_tree, q.idx, q.x);
        } else {
            results.emplace_back(find_unit_by_soldier_idx(fenwick_tree, q.idx));
        }
    }

    return results;
}

int main(){

    ios_
    ::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> initial_unit_sizes(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> initial_unit_sizes[i];
    }

    int q;
    cin >> q;

    vector<Query> queries(q);
    for (auto& q : queries) {
        cin >> q.type >> q.idx;
        if (q.type == 1) {
            cin >> q.x;
        }
    }

    vector<int> results = process_queries(initial_unit_sizes, queries);
    for (const int unit : results) {
        cout << unit << '\n';
    }

    return 0;
}