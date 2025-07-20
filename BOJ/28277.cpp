#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Query {
    int type;
    int a;
    int b = -1;
};

void merge_set(vector<set<int>>& sets, int a, int b) {
    if (sets[a].size() < sets[b].size()) {
        swap(sets[a], sets[b]);
    }
    sets[a].insert(sets[b].begin(), sets[b].end());
    sets[b].clear();
}

vector<int> process_queries(vector<set<int>>& sets, const vector<Query>& queries) {
    vector<int> results;
    for (auto& q : queries) {
        if (q.type == 1) {
            merge_set(sets, q.a, q.b);
        } else {
            results.push_back(sets[q.a].size());
        }
    }
    return results;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<set<int>> sets(n + 1);
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;        
        for (int j = 0; j < x; ++j) {
            int y;
            cin >> y;
            sets[i].insert(y);
        }
    }

    vector<Query> queries(q);

    for (auto& q : queries) {
        cin >> q.type;
        if (q.type == 1) {
            cin >> q.a >> q.b;
        } else {
            cin >> q.a;
        }
    }

    auto results = process_queries(sets, queries);
    for (auto& sz : results) {
        cout << sz << '\n';
    }

    return 0;
}