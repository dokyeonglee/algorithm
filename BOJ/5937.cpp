#include <iostream>
#include <queue>

using namespace std;

void topology_sort(vector<vector<int>>& graph, vector<int>& in_degree){

    int n = graph.size() - 1;

    queue<int> q;
    vector<int> result(n + 1);

    for(int i = 1; i <= n; i++){
        if(in_degree[i] == 0){
            q.push(i);
            result[i] = 1;
        }
    }

    int x = q.size();
    int answer = 0;

    for(int i = 0; i < n; i++){
        int now = q.front();
        q.pop();
        if(result[now] == x){
            answer = now;
            break;
        }
        for(int next : graph[now]){
            result[next] += result[now];
            if(--in_degree[next] == 0){
                q.push(next);
            }
        }
    }

    if(x != 1){
        cout << answer << "\n";
    }

    while(graph[answer].size() == 1){
        answer = graph[answer][0];
        cout << answer << "\n";
    }

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> graph(n + 1);
    vector<int> in_degree(n + 1);

    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        in_degree[b]++;
    }

    topology_sort(graph, in_degree);

    return 0;
}