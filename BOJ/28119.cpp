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

int mst(vector<pair<int, pair<int, int>>>& edges, vector<int>& parent){

    int result = 0;

    for(auto edge : edges){
        int c = edge.first;
        auto p = edge.second;
        if(find_parent(parent, p.first) != find_parent(parent, p.second)){
            union_parent(parent, p.first, p.second);
            result += c;
        }
    }


    return result;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, s;
    cin >> n >> m >> s;

    vector<int> parent(n + 1);
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    vector<pair<int, pair<int, int>>> edges(m);
    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        edges[i] = make_pair(c, make_pair(u, v));
    }

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
    }

    sort(edges.begin(), edges.end());

    cout << mst(edges, parent);

    return 0;
}