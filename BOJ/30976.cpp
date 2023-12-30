#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>>& graph, vector<int>& d, vector<int>& visited, int cnt, int b){
    for(int& g : graph[b]){
        if(visited[g] == cnt){
            continue;
        }
        visited[g] = cnt;
        if(d[g] == -1 or dfs(graph, d, visited, cnt, d[g])){
            d[g] = b;
            return true;
        }
    }
    return false;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> girl(n);
    vector<int> boy(m);

    for(int& g : girl){
        cin >> g;
    }

    for(int& b : boy){
        cin >> b;
    }

    vector<int> like(n);
    for(int& l : like){
        cin >> l;
    }

    vector<vector<int>> graph(m);

    for(int i = 0; i < m; i++){
        int l;
        cin >> l;
        for(int j = 0; j < n; j++){
            if(boy[i] < like[j] and girl[j] > l){
                graph[i].push_back(j);
            }
        }
    }

    int answer = 0;
    vector<int> d(n, -1);
    vector<int> visited(n);

    for(int i = 0; i < m; i++){
        if(dfs(graph, d, visited, i + 1, i)){
            answer++;
        }
    }

    cout << answer;

    return 0;
}