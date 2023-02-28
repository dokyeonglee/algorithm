#include <iostream>
#include <queue>

using namespace std;

int answer = 987654321;

int topology(vector<vector<int>>& adj, vector<int>& _in_degree, vector<int>& times, int e){

    vector<int> in_degree(_in_degree);
    vector<int> result(adj.size());

    queue<int> q;
    for(int i = 1; i < adj.size(); i++){
        if(in_degree[i] == 0){
            result[i] = times[i];
            q.push(i);
        }
    }

    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int next : adj[now]){
            result[next] = max(result[next], result[now]);
            if(--in_degree[next] == 0){
                result[next] += times[next];
                q.push(next);
            }
        }
    }

    return result[e];

}

void solve(vector<vector<int>>& adj, vector<int>& in_degree, vector<int>& times, int idx, int e, int k){
    if(k == 0){
        answer = min(answer, topology(adj, in_degree, times, e));
    }else{
        for(int i = idx + 1; i < adj.size(); i++){
            if(i == e){
                continue;
            }
            int temp = times[i];
            times[i] = 0;
            solve(adj, in_degree, times, i, e, k - 1);
            times[i] = temp;
        }
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> times(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> times[i];
    }

    vector<vector<int>> adj(n + 1);
    vector<int> in_degree(n + 1);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        in_degree[v]++;
    }

    int e = 0;
    for(int i = 1; i <= n; i++){
        if(adj[i].size() == 0){
            e = i;
            break;
        }
    }

    solve(adj, in_degree, times, 1, e, k);

    cout << answer;

    return 0;
}