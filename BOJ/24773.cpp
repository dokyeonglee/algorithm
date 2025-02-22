#include <iostream>
#include <vector>

using namespace std;

int x;
bool check;

int dfs(vector<vector<int>>& adj, vector<int>& discover, int now, int p){

    if(check){
        return -1;
    }

    discover[now] = ++x;

    int result = discover[now];

    for(int& next : adj[now]){
        if(next == p){
            continue;
        }
        if(!discover[next]){
            int temp = dfs(adj, discover, next, now);
            result = min(result, temp);
            if(temp > discover[now]){
                check = true;
                return -1;
            }
        }else{
            result = min(result, discover[next]);
        }
    }

    return result;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(1){

        int n, m;
        cin >> n >> m;

        if(n == 0 and m == 0){
            break;
        }

        check = false;

        vector<vector<int>> adj(n);
        vector<int> discover(n);
        vector<bool> cut(n);

        while(m--){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i = 0; i < n; i++){
            if(!discover[i]){
                dfs(adj, discover, i, -1);
                if(check){
                    break;
                }
            }
        }

        if(check){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }

    }    

    return 0;

}