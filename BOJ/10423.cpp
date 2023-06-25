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

void union_parent(vector<int>& parent, vector<bool>& check, int x, int y){
    x = find_parent(parent, x);
    y = find_parent(parent, y);
    check[x] = (check[x] | check[y]);
    parent[y] = x;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> parent(n + 1);
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    vector<bool> check(n + 1);

    for(int i = 0; i < k; i++){
        int x;
        cin >> x;
        check[x] = true;
    }

    vector<pair<int, pair<int, int>>> edges(m);

    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        edges[i] = make_pair(c, make_pair(u, v));
    }

    sort(edges.begin(), edges.end());

    int answer = 0;

    for(int i = 0; i < m; i++){
        int pu = find_parent(parent, edges[i].second.first);
        int pv = find_parent(parent, edges[i].second.second);
        int c = edges[i].first;
        if(pu != pv and !(check[pu] and check[pv])){
            answer += c;
            union_parent(parent, check, pu, pv);
        }
    }

    cout << answer;    

    return 0;
}