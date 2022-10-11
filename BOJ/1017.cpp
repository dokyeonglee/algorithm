#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(vector<vector<int>>& adj, vector<int>& d, vector<int>& d2, vector<bool>& visited, int x){
    for(int i = 0; i < adj[x].size(); i++){
        int now = adj[x][i];
        if(visited[now]){
            continue;
        }
        visited[now] = true;
        if(d[now] == -1 or dfs(adj, d, d2, visited, d[now])){
            d[now] = x;
            d2[x] = now;
            return true;
        }
    }
    return false;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<bool> is_prime(2001, true);
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i * i <= 2000; i++){
        if(is_prime[i]){
            for(int j = i * i; j <= 2000; j += i){
                is_prime[j] = false;
            }
        }
    }

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<vector<int>> _numbers(2);

    for(int i = 0; i < n; i++){
        _numbers[arr[i] % 2].push_back(arr[i]);
    }

    if(_numbers[0].size() != _numbers[1].size()){
        cout << -1;
        return 0;
    }

    int idx = arr[0] % 2;

    vector<vector<int>> adj(n / 2);
    for(int i = 0; i < n / 2; i++){
        for(int j = 0; j < n / 2; j++){
            if(is_prime[_numbers[idx][i] + _numbers[idx ^ 1][j]]){
                adj[i].push_back(j);
            }
        }
    }

    vector<int> answer;

    for(int x : adj[0]){
        vector<int> d(n / 2, -1);
        vector<int> d2(n / 2, -1);
        int cnt = 1;
        d[x] = 0;
        d2[0] = x;
        for(int i  = 1; i < n / 2; i++){    
            vector<bool> visited(n / 2, false);
            visited[x] = true;
            if(dfs(adj, d, d2, visited, i)){
                cnt++;
            }
        }
        if(cnt == n / 2){
            answer.push_back(_numbers[idx ^ 1][d2[0]]);
        }
    }
    
    if(answer.size() == 0){
        cout << -1;
    }else{
        sort(answer.begin(), answer.end());
        for(int i = 0; i < answer.size(); i++){
            cout << answer[i] << " ";
        }
    }

    return 0;
}