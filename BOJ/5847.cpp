#include <iostream>
#include <queue>

using namespace std;


int topology_sort(vector<vector<int>>& graph, vector<int>& in_degree, vector<int>& times){

    vector<int> result(graph.size());
    
    int answer = 0;

    queue<int> q;
    for(int i = 1; i < graph.size(); i++){
        if(in_degree[i] == 0){
            result[i] = times[i];
            q.push(i);
        }
    }

    while(!q.empty()){
    	
        int now = q.front();
        q.pop();
        
        answer = max(answer, result[now]);
        
        for(int next : graph[now]){
            result[next] = max(result[next], result[now]);
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

    int n, m;
    cin >> n >> m;

    vector<int> times(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> times[i];
    }
    
    vector<vector<int>> graph(n + 1);
    vector<int> in_degree(n + 1);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        in_degree[v]++;
    }

    cout << topology_sort(graph, in_degree, times);

    return 0;
}