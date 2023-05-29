#include <iostream>
#include <queue>

using namespace std;

int bfs(vector<int>& arr, int m, int k){

    int _max = 0;
    for(int i = 0; i < arr.size(); i++){
        _max = max(_max, arr[i]);
    }

    vector<bool> visited(m * _max + 1);
    visited[0] = true;

    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));

    int result = 0;

    while(!q.empty()){
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(now % k == 0){
            result = max(result, now);
        }
        for(int i = 0; i < arr.size(); i++){
            int next = now + arr[i];
            if(cnt + 1 <= m and !visited[next]){
                visited[next] = true;
                q.push(make_pair(next, cnt + 1));
            }
        }
    }

    return result;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << bfs(arr, m, k);

    return 0;
}