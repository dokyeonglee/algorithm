#include <iostream>
#include <queue>

using namespace std;

void topology_sort(vector<vector<int>>& adj, vector<int>& in_degree){

    queue<int> q;

    int r = 1;
    
    for(int i = 1; i < in_degree.size(); i++){
        if(in_degree[i] == 0){
            q.push(i);
        }
    }

    bool check = true;

    while(!q.empty()){
        int sz = q.size();
        if(sz > 1){
            check = false;
        }
        while(sz--){
            int now = q.front();
            q.pop();
            cout << now << "\n";
            for(int& next : adj[now]){
                if(--in_degree[next] == 0){
                    q.push(next);
                }
            }
        }
    }

    if(check){
        cout << 0;
    }else{
        cout << 1;
    }

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> in_degree(n + 1);

    while(m--){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        in_degree[v]++;
    }

    topology_sort(adj, in_degree);

    return 0;

}