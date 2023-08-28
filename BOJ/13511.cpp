#include <iostream>
#include <vector>

using namespace std;

int parent[100001][18];
long long cost[100001];
int depth[100001];
bool visited[100001];
vector<pair<int, int>> tree[100001];

void dfs(int now, int d, long long p){

    visited[now] = true;
    depth[now] = d;
    cost[now] = p;

    for(auto& e : tree[now]){
        int next = e.first;
        int c = e.second;
        if(!visited[next]){
            parent[next][0] = now;
            dfs(next, d + 1, p + c);
        }
    }

}

int lca(int u, int v){

    if(depth[u] > depth[v]){
        swap(u, v);
    }

    for(int i = 17; i >= 0; i--){
        if(depth[v] - depth[u] >= (1 << i)){
            v = parent[v][i];
        }
    }

    if(u == v){
        return u;
    }

    for(int i = 17; i >= 0; i--){
        if(parent[u][i] != parent[v][i]){
            u = parent[u][i];
            v = parent[v][i];
        }
    }

    return parent[u][0];
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i < n; i++){
        int u, v, c;
        cin >> u >> v >> c;
        tree[u].push_back(make_pair(v, c));
        tree[v].push_back(make_pair(u, c));
    }

    dfs(1, 0, 0);

    for(int i = 1; i < 18; i++){
        for(int j = 1; j <= n; j++){
            parent[j][i] = parent[parent[j][i - 1]][i - 1];
        }
    }

    int q;
    cin >> q;

    while(q--){

        int c, u, v;
        cin >> c >> u >> v;

        int p = lca(u, v);

        if(c == 1){
            cout << cost[u] + cost[v] - 2 * cost[p] << "\n";
        }else{

            int k;
            cin >> k;

            int answer = p;
            
            if(depth[u] - depth[p] + 1 > k){
                k--;
                answer = u;
            }else if(depth[u] - depth[p] + 1 < k){
                k -= depth[u] - depth[p] + 1;
                k = depth[v] - depth[p] - k;
                answer = v;
            }else{
                k = 0;
            }

            for(int i = 17; i >= 0; i--){
                if(k & (1 << i)){
                    answer = parent[answer][i];
                }
            }

            cout << answer << "\n";
        }
    }

    return 0;
}