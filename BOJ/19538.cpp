#include <iostream>
#include <queue>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    vector<int> cnt(n + 1);

    for(int i = 1; i <= n; i++){
        while(1){
            int y;
            cin >> y;
            if(y == 0){
                break;
            }
            adj[i].push_back(y);
        }
        cnt[i] = (adj[i].size() + 1) / 2;
    }

    int m;
    cin >> m;

    vector<int> answer(n + 1, -1);
    vector<bool> visited(n + 1);
    queue<int> q;

    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        answer[x] = 0;
        visited[x] = true;
        q.push(x);
    }

    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int next : adj[now]){
            if(--cnt[next] == 0 and !visited[next]){
                answer[next] = answer[now] + 1;
                visited[next] = true;
                q.push(next);
            }
        }
    }

    for(int i = 1; i < answer.size(); i++){
        cout << answer[i] << " ";
    }

    return 0;
}