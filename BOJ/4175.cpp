#include <iostream>
#include <queue>

using namespace std;

void topology_sort(vector<vector<int>>& graph, vector<int>& in_degree){

    vector<int> result;

    queue<int> q;

    for(int i = 1; i < graph.size(); i++){
        if(in_degree[i] == 0){
            q.push(i);
        }
    }

    for(int i = 1; i < graph.size(); i++){

        if(q.empty()){
            cout << "IMPOSSIBLE\n";
            return;
        }

        int now = q.front();
        q.pop();

        result.push_back(now);

        for(int next : graph[now]){
            if(--in_degree[next] == 0){
                q.push(next);
            }
        }
    }

    for(int i = 0; i < result.size(); i++){
        cout << result[i] << "\n";
    }

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(1){

        int n, m;
        cin >> n >> m;

        if(n == 0 and m == 0){
            break;
        }

        vector<vector<int>> graph(n + 1);
        vector<int> in_degree(n + 1);

        for(int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            in_degree[b]++;
        }

        topology_sort(graph, in_degree);

    }

    return 0;
}