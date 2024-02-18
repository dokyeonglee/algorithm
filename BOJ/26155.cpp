#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_parent(vector<int>& parent, int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = find_parent(parent, parent[x]);
}

void union_parent(vector<int>& parent, int x, int y){
    x = find_parent(parent, x);
    y = find_parent(parent, y);
    parent[y] = x;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> parent(n + 1);
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    vector<pair<double, pair<int, int>>> pipe(m);

    for(int i = 0; i < m; i++){
        int u, v;
        double p;
        cin >> u >> v >> p;
        pipe[i] = make_pair(p, make_pair(u, v));
    }

    int q;
    cin >> q;

    vector<pair<double, int>> query(q);

    for(int i = 0; i < q; i++){
        cin >> query[i].first;
        query[i].second = i;
    }

    sort(pipe.rbegin(), pipe.rend());
    sort(query.rbegin(), query.rend());

    vector<int> answer(q);

    int idx = 0;
    int result = n;

    for(int i = 0; i < q; i++){
        double p = query[i].first;
        while(idx < m and p <= pipe[idx].first){
            int u = pipe[idx].second.first;
            int v = pipe[idx++].second.second;
            if(find_parent(parent, u) != find_parent(parent, v)){
                union_parent(parent, u, v);
                result--;
            }
        }
        answer[query[i].second] = result;
    }

    for(int i = 0; i < q; i++){
        cout << answer[i] << "\n";
    }

    return 0;
}