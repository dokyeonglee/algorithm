#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using Query = pair<int, pair<int, int>>;

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

vector<ll> process_queries(const vector<Query>& queries, const int n) {
    vector<ll> fenwick_tree(n + 1);
    vector<ll> results;

    for (auto& q : queries) {
        int type = q.first;
        if (type == 1) {
            int day = q.second.first;
            int amount = q.second.second;
            update(fenwick_tree, day, amount);
        } else {
            int start_day = q.second.first;
            int end_day = q.second.second;
            ll delta = prefix_sum(fenwick_tree, end_day) - prefix_sum(fenwick_tree, start_day - 1);
            results.emplace_back(delta);
        }
    }

    return results;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<Query> queries(q);
    for (auto& q : queries) {
        cin >> q.first >> q.second.first >> q.second.second;
    }

    auto results = process_queries(queries, n);
    for (const auto& delta : results) {
        cout << delta << '\n';
    }

    return 0;
}