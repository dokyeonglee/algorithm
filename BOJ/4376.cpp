#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>>& graph, vector<int>& d, vector<int>& visited, int cnt, int g){

    for(int& h : graph[g]){
        if(visited[h] == cnt){
            continue;
        }
        visited[h] = cnt;
        if(d[h] == -1 or dfs(graph, d, visited, cnt, d[h])){
            d[h] = g;
            return true;
        }
    }

    return false;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, s, v;

    while(cin >> n >> m >> s >> v){

        vector<pair<double, double>> gopher(n);
        vector<pair<double, double>> hole(m);

        for(auto& g : gopher){
            cin >> g.first >> g.second;
        }

        for(auto& h : hole){
            cin >> h.first >> h.second;
        }

        vector<vector<int>> graph(n);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                double dist_square = (gopher[i].first - hole[j].first) * (gopher[i].first - hole[j].first) + (gopher[i].second - hole[j].second) * (gopher[i].second - hole[j].second);
                if(dist_square <= v * v * s * s){
                    graph[i].push_back(j);
                }
            }
        }

        vector<int> d(m, -1);
        vector<int> visited(m);

        int answer = n;

        for(int i = 0; i < n; i++){
            if(dfs(graph, d, visited, i + 1, i)){
                answer--;
            }
        }

        cout << answer << "\n";

    }

    return 0;
}