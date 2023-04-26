#include <iostream>
#include <queue>

using namespace std;

vector<int> topology_sort(vector<vector<int>>& graph, vector<int>& in_degree){

    vector<int> result;
    vector<bool> visited(graph.size());

    queue<int> q;
    for(int i = 1; i < graph.size(); i++){
        if(in_degree[i] < 2){
            q.push(i);
        }
    }

    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(visited[now]){
            continue;
        }
        visited[now] = true;
        for(int next : graph[now]){
            if(--in_degree[next] < 2){
                q.push(next);
            }
        }
    }

    for(int i = 1; i < graph.size(); i++){
        if(in_degree[i] == 2){
            result.push_back(i);
        }
    }
    
    return result;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> graph(n + 1);
    vector<int> in_degree(n + 1);

    for(int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        graph[i].push_back(a);
        graph[i].push_back(b);
        in_degree[a]++;
        in_degree[b]++;
    }

    vector<int> answer = topology_sort(graph, in_degree);

    cout << answer.size() << "\n";
    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << " ";
    }

    return 0;
}