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

    vector<pair<int, pair<int, int>>> edges(m);
    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        edges[i] = make_pair(c, make_pair(u, v));
    }
    
    sort(edges.begin(), edges.end());

    int answer = 1;

    for(auto& edge : edges){
        int c = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if(find_parent(parent, u) != find_parent(parent, v)){
            if(answer != c){
                break;
            }
            answer++;
            union_parent(parent, u, v);
        }
    }

    cout << answer;

    return 0;
}