#include <iostream>
#include <queue>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> tree(n);
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> in_degree(n);

    for(int i = 0; i < n; i++){
        in_degree[i] = tree[i].size();
    }

    vector<bool> check(n, true);
    queue<int> q;

    for(int i = 0; i < n; i++){
        if(in_degree[i] == 1){
            check[i] = false;
            q.push(i);
        }
    }

    while(q.size() > 2){

        int sz = q.size();

        for(int i = 0; i < sz; i++){

            int now = q.front();
            q.pop();

            for(int& next : tree[now]){
                if(!check[next]){
                    continue;
                }
                if(--in_degree[next] == 1){
                    check[next] = false;
                    q.push(next);
                }
            }
        }

    }

    while(!q.empty()){
        check[q.front()] = true;
        q.pop();
    }

    for(int i = 0; i < n; i++){
        if(check[i]){
            cout << i << " ";
        }
    }

    return 0;
}