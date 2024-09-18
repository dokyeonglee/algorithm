#include <iostream>
#include <queue>

using namespace std;

void topology_sort(vector<vector<pair<int, int>>>& adj, vector<int>& in_degree, vector<int>& answer){

    queue<int> q;

    for(int i = 1; i < in_degree.size(); i++){
        if(in_degree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(auto& e : adj[now]){
            int next = e.first;
            answer[next] = max(answer[next], answer[now] + e.second);
            if(--in_degree[next] == 0){
                q.push(next);
            }
        }
    }

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<pair<int, int>>> adj(n + 1);
    vector<int> in_degree(n + 1);

    vector<int> answer(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> answer[i];
    }

    while(q--){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].emplace_back(v, c);
        in_degree[v]++;
    }

    topology_sort(adj, in_degree, answer);

    for(int i = 1; i <= n; i++){
        cout << answer[i] << "\n";
    }

    return 0;
}