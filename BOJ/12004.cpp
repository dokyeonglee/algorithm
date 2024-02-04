#include <iostream>
#include <vector>

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

    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> parent(n + 1);

    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    vector<int> arr(n);
    for(auto& a : arr){
        cin >> a;
    }

    vector<int> answer(n);

    vector<bool> check(n + 1);

    int cnt = 0;

    for(int i = n - 1; i >= 0; i--){
        int u = arr[i];
        check[u] = true;
        cnt++;
        for(int& v : adj[u]){
            if(!check[v]){
                continue;
            }
            if(find_parent(parent, u) != find_parent(parent, v)){
                union_parent(parent, u, v);
                cnt--;
            }
        }
        if(cnt == 1){
            answer[i] = 1;
        }
    }

    for(int i = 0; i < n; i++){
        if(answer[i]){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }

    return 0;
}