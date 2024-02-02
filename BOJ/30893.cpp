#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> path;

bool dfs(vector<vector<int>>& tree, int s, int e, int p){
    if(s == e){
        return true;
    }
    for(int x : tree[s]){
        if(x != p){
            if(dfs(tree, x, e, s)){
                path.push_back(x);
                return true;
            }
        }
    }
    return false;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, s, e;
    cin >> n >> s >> e;

    vector<vector<int>> tree(n + 1);

    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(tree, s, e, -1);
    path.push_back(s);

    reverse(path.begin(), path.end());

    int now = s;

    vector<bool> visited(n + 1);

    visited[s] = true;
    int idx = 1;

    while(now != e){
        if(idx % 2 == 0){
            bool check = false;
            for(int& next : tree[now]){
                if(!visited[next] and next != path[idx]){
                    check = true;
                    break;
                }
            }
            if(check){
                cout << "Second";
                return 0; 
            }
        }
        now = path[idx++];
        visited[now] = true;
    }

    cout << "First";

    return 0;
}