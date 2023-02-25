#include <iostream>
#include <queue>

using namespace std;

void topology_sort(vector<vector<pair<int, int>>>& adj, vector<int>& in_degree, vector<pair<int, int>>& candidate){
    
    vector<int> score(adj.size());
    vector<int> predecessor(adj.size());

    queue<int> q;

    for(int i = 1; i < adj.size(); i++){
        if(in_degree[i] == 0){
            q.push(i);
        }
    }

    for(int i = 0; i < adj.size(); i++){
        int now = q.front();
        q.pop();
        for(auto e : adj[now]){
            int next = e.first;
            int c = e.second;
            if(score[next] < score[now] + c){
                score[next] = score[now] + c;
                predecessor[next] = now;
            }
            if(--in_degree[next] == 0){
                q.push(next);
            }
        }
    }

    int max_score = 0;
    int idx = 0;
    for(int i = 0; i < candidate.size(); i++){
        if(max_score < score[candidate[i].first] + candidate[i].second){
            max_score = score[candidate[i].first] + candidate[i].second;
            idx = i;
        }
    }

    cout << max_score << "\n";

    vector<int> answer = {1};
    
    int u = candidate[idx].first;

    while(u != 1){
        answer.push_back(u);
        u = predecessor[u];       
    }

    answer.push_back(1);

    for(int i = answer.size() - 1; i >= 0; i--){
        cout << answer[i] << " ";
    }   

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<pair<int, int>>> adj(n + 1);
    vector<int> in_degree(n + 1);

    int m;
    cin >> m;

    vector<pair<int, int>> candidate;

    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        if(v != 1){
            adj[u].push_back(make_pair(v, c));
            in_degree[v]++;
        }else{
            candidate.push_back(make_pair(u, c));
        }
    }

    topology_sort(adj, in_degree, candidate);

    return 0;
}