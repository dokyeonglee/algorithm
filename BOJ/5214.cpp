#include <iostream>
#include <queue>

using namespace std;

int bfs(vector<vector<int>>& graph, int dst){

    vector<bool> visited(graph.size());
    visited[1] = true;

    queue<pair<int, int>> q;
    q.push(make_pair(1, 1));

    while(!q.empty()){
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(now == dst){
            return (cnt + 1) / 2;
        }
        for(int next : graph[now]){
            if(!visited[next]){
                visited[next] = true;
                q.push(make_pair(next, cnt + 1));
            }
        }
    }

    return -1;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, m;
    cin >> n >> k >> m;

    if(n == 1){
        cout << 1;
        return 0;
    }
    
    vector<vector<int>> graph(n + m + 1);
 
    for(int i = 1; i <= m; i++){
        for(int j = 0; j < k; j++){
            int x;
            cin >> x;
            graph[x].push_back(n + i);
            graph[n + i].push_back(x);
        }
    }
    

    cout << bfs(graph, n);

    return 0;
}