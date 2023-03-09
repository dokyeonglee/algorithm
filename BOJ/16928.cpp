#include <iostream>
#include <queue>

using namespace std;

int bfs(vector<int>& jump){
    
    vector<bool> visited(101);
    visited[1] = true;

    queue<pair<int, int>> q;
    q.push(make_pair(1, 0));

    while(!q.empty()){

        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(now == 100){
            return cnt;
        }
        
        for(int i = 1; i <= 6; i++){
            if(now + i <= 100){ 
                int next = jump[now + i];
                if(!visited[next]){
                    visited[next] = true;
                    q.push(make_pair(next, cnt + 1));
                }
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

    vector<int> jump(101);
    
    for(int i = 1; i <= 100; i++){
        jump[i] = i;
    }

    for(int i = 0; i < n + m; i++){
        int u, v;
        cin >> u >> v;
        jump[u] = v;
    }

    cout << bfs(jump);

    return 0;
}