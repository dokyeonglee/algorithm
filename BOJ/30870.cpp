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
    parent[y] = x;
}

vector<int> get_delete_order(vector<vector<int>>& adj, vector<int>& first_delete){

    vector<int> delete_order(adj.size());

    queue<int> q;

    for(int& now : first_delete){
        delete_order[now] = 1;
        q.push(now);
    }

    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int& next : adj[now]){
            if(delete_order[next] == 0){
                delete_order[next] = delete_order[now] + 1;
                q.push(next);
            }
        }
    }

    return delete_order;

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

    vector<vector<int>> adj(n + 1);
    vector<pair<int, int>> edges(m);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges[i] = make_pair(u, v);
    }

    vector<int> first_delete(k);
    for(int& a : first_delete){
        cin >> a;
    }

    auto delete_order = get_delete_order(adj, first_delete);

    vector<vector<int>> arr(n + 1);

    for(int i = 0; i < m; i++){
        int u = edges[i].first;
        int v = edges[i].second;
        arr[min(delete_order[u], delete_order[v])].push_back(i);
    }

    for(int i = n - 1; i >= 1; i--){
        for(auto& j : arr[i]){
            int now = edges[j].first;
            int next = edges[j].second;
            if(find_parent(parent, now) != find_parent(parent, next)){
                union_parent(parent, now, next);
            }else{
                cout << i;
                return 0;
            }
        }
    }

    cout << n;

    return 0;

}