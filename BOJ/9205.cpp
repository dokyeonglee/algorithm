#include <iostream>
#include <queue>

using namespace std;

string bfs(vector<vector<int>>& graph){

    vector<bool> visited(graph.size());
    visited[0] = true;

    queue<int> q;
    q.push(0);

    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(now == graph.size() - 1){
            return "happy\n";
        }
        for(int next : graph[now]){
            if(!visited[next]){
                visited[next] = true;
                q.push(next);
            }
        }
    }

    return "sad\n";
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        vector<pair<int, int>> arr(n + 2);
        for(int i = 0; i < arr.size(); i++){
            cin >> arr[i].first >> arr[i].second;
        }

        vector<vector<int>> graph(n + 2);
        for(int i = 0; i < arr.size(); i++){
            for(int j = 0; j < arr.size(); j++){
                int dist = abs(arr[i].first - arr[j].first) + abs(arr[i].second - arr[j].second);
                if(dist <= 1000){
                    graph[i].push_back(j);
                }
            }
        }

        cout << bfs(graph);

    }

    return 0;
}