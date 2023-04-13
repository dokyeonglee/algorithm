#include <iostream>
#include <queue>

using namespace std;

int bfs(vector<vector<int>>& arr, int n, int src, int dst){

    vector<bool> visited(arr.size());
    visited[src] = true;

    queue<pair<int, int>> q;
    q.push(make_pair(0, src));

    while(!q.empty()){
        int cnt = q.front().first;
        int now = q.front().second;
        q.pop();
        if(now == dst){
            return cnt - 1;
        }
        for(int next : arr[now]){
            if(!visited[next]){
                visited[next] = true;
                int next_cnt = cnt + (next > n);
                q.push(make_pair(next_cnt, next));
            }
        }
    }

    return -1;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n + m + 1);

    for(int i = 1; i <= m; i++){
        while(1){
            int x;
            cin >> x;
            if(x == -1){
                break;
            }
            arr[x].push_back(n + i);
            arr[n + i].push_back(x);
        }
    }

    int src, dst;
    cin >> src >> dst;

    if(src == dst){
        cout << 0;
        return 0;
    }

    cout << bfs(arr, n, src, dst);

    return 0;
}