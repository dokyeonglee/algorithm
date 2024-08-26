#include <iostream>
#include <vector>

using namespace std;

bool operator < (const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b){
    return !(a.first > b.first or a.second.first > b.second.first or a.second.second > b.second.second);
}

bool dfs(vector<vector<int>>& adj, vector<int>& d, vector<bool>& visited, int x){
    for(int& y : adj[x]){
        if(visited[y]){
            continue;
        }
        visited[y] = true;
        if(d[y] == -1 or dfs(adj, d, visited, d[y])){
            d[y] = x;
            return true;
        }
    }
    return false;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, pair<int, int>>> sharks(n);
    for(auto& shark : sharks){
        cin >> shark.first >> shark.second.first >> shark.second.second;
    }

    vector<vector<int>> adj(n + 1);

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(sharks[i] == sharks[j] or sharks[j] < sharks[i]){
                adj[i].push_back(j);
            }else if(sharks[i] < sharks[j]){
                adj[j].push_back(i);
            }
        }
    }

    vector<int> d(n, -1);

    int answer = n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2; j++){
            vector<bool> visited(n);
            if(dfs(adj, d, visited, i)){
                answer--;
            }
        }
    }

    cout << answer;

    return 0;
}