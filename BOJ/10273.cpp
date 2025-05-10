#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

vector<int> find_path(const vector<int>& predecessor, int last_cave){
    vector<int> path;
    int now = last_cave;
    while(now != -1){
        path.emplace_back(now);
        now = predecessor[now];
    }
    reverse(path.begin(), path.end());
    return path;
}

void find_max_earning_path(const vector<vector<pair<int, int>>>& adj, vector<int>& in_degree, const vector<int>& value){

    int n = adj.size() - 1;

    vector<int> dp(n + 1, INT_MIN);
    dp[1] = value[1];

    vector<int> predecessor(adj.size(), -1);

    queue<int> q;
    q.emplace(1);

    while(!q.empty()){

        int now = q.front();
        q.pop();

        for(auto& [next, cost] : adj[now]){
            if(dp[next] < dp[now] + value[next] - cost){
                predecessor[next] = now;
                dp[next] = dp[now] + value[next] - cost;
            }
            if(--in_degree[next] == 0){
                q.emplace(next);
            }
        }

    }

    int max_earning_cave = max_element(dp.begin(), dp.end()) - dp.begin();
    int max_earning = dp[max_earning_cave];
    const vector<int> path = find_path(predecessor, max_earning_cave);
    
    cout << dp[max_earning_cave] << ' ' << path.size() << '\n';
    for(int cave : path){
        cout << cave << ' ';
    }
    cout << '\n';

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){

        int n, e;
        cin >> n >> e;

        vector<int> value(n + 1);
        for(int i = 1; i <= n; i++){
            cin >> value[i];
        }

        vector<vector<pair<int, int>>> adj(n + 1);
        vector<int> in_degree(n + 1);

        while(e--){
            int u, v, c;
            cin >> u >> v >> c;
            adj[u].emplace_back(v, c);
            in_degree[v]++;
        }

        find_max_earning_path(adj, in_degree, value);

    }

    return 0;

}