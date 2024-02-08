#include <iostream>
#include <queue>

using namespace std;

int distance(pair<int, int>& a, pair<int, int>& b){
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int bfs(vector<pair<int, int>>& arr, vector<int>& p, vector<int>& r){

    int n = arr.size() - 1;
    int m = p.size();

    vector<bool> visited(arr.size(), true);

    for(int i = 0; i < m; i++){
        for(int j = 1; j <= n; j++){
            if(distance(arr[p[i]], arr[j]) <= r[i + 1]){
                visited[j] = false;
            }
        }
    }

    queue<int> q;

    for(int i = 1; i <= n; i++){
        if(visited[i]){
            q.push(i);
        }
    }

    int result = 0;

    while(!q.empty()){

        int now = q.front();
        q.pop();

        result++;

        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                if(distance(arr[now], arr[i]) <= r[0]){
                    visited[i] = true;
                    q.push(i);
                }
            }
        }

    }

    return result;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    vector<int> p(m);
    for(int& x : p){
        cin >> x;
    }

    vector<int> r(m + 1);
    for(int& x : r){
        cin >> x;
        x *= x;
    }
    
    cout << bfs(arr, p, r);

    return 0;
}