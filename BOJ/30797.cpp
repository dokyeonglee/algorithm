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

    vector<pair<pair<int, int>, pair<int, int>>> edges(m);
    for(int i = 0; i < m; i++){
        int u, v, c, t;
        cin >> u >> v >> c >> t;
        edges[i] = make_pair(make_pair(c, t), make_pair(u, v));
    }

    sort(edges.begin(), edges.end());

    long long cost = 0;
    int time = 0;

    int cnt = 0;

    for(int i = 0; i < m; i++){
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        if(find_parent(parent, u) != find_parent(parent, v)){
            cnt++;
            cost += edges[i].first.first;
            time = max(time, edges[i].first.second);
            union_parent(parent, u, v);
        }
    }

    if(cnt == n - 1){
        cout << time << " " << cost;
    }else{
        cout << -1;
    }

    return 0;
}
