#include <iostream>
#include <queue>

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
    if(x != y){
        parent[y] = x;
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> parent(n);
    for(int i = 0; i < n; i++){
        parent[i] = i;
    }

    vector<pair<int, int>> edges;

    int u, v;

    while(m--){
        char c;
        cin >> u >> c >> v;
        if(c == '='){
            union_parent(parent, u, v);
        }else{
            edges.emplace_back(u, v);
        }
    }

    vector<vector<int>> adj(n + 1);
    vector<int> in_degree(n + 1);

    for(auto& e : edges){

        u = find_parent(parent, e.first);
        v = find_parent(parent, e.second);

        if(u == v){
            cout << "inconsistent";
            return 0;
        }

        adj[u].emplace_back(v);
        in_degree[v]++;

    }

    queue<int> q;

    int x = 0;
    
    for(int i = 0; i < n; i++){
        if(find_parent(parent, i) == i){
            x++;
            if(in_degree[i] == 0){
                q.push(i);
            }
        }
    }

    for(int i = 0; i < x; i++){
 
        if(q.empty()){
            cout << "inconsistent";
            return 0;
        }

        int now = q.front();
        q.pop();

        for(auto& next : adj[now]){
            if(--in_degree[next] == 0){
                q.push(next);
            }
        }

    }

    cout << "consistent";

    return 0;
}