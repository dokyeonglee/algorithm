#include <iostream>
#include <queue>

using namespace std;

int topology_sort(vector<vector<pair<int, int>>>& adj, vector<int>& in_degree, vector<int>& times){

    queue<int> q;

    for(int i = 1; i < adj.size(); i++){
        if(in_degree[i] == 0){
            q.push(i);
        }
    }

    vector<int> result(times);

    int answer = 0;

    while(!q.empty()){

        int now = q.front();
        q.pop();

        answer = max(answer, result[now]);

        for(auto e : adj[now]){

            int next = e.first;
            int c = e.second;

            result[next] = max(result[next], result[now] + c);

            if(--in_degree[next] == 0){
                result[next] += times[next];
                q.push(next);
            }
            
        }
    }

    return answer;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> classes(n + 1);
    vector<int> times(n + 1);

    for(int i = 1; i <= n; i++){
        int c;
        cin >> c >> times[i];
        classes[c].push_back(i);
    }

    vector<vector<pair<int, int>>> adj(n + 1);
    vector<int> in_degree(n + 1);

    for(int i = 2; i <= n; i++){
        for(int j = 0; j < classes[i].size(); j++){
            for(int k = 0; k < classes[i - 1].size(); k++){
                int u = classes[i - 1][k];
                int v = classes[i][j];
                adj[u].push_back(make_pair(v, (u - v) * (u - v)));
                in_degree[v]++;
            }
        }
    }

    cout << topology_sort(adj, in_degree, times);

    return 0;
}