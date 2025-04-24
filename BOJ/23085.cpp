#include <iostream>
#include <queue>

using namespace std;

int bfs(int src, int n, int k){

    vector<bool> visited(n + 1);
    visited[src] = true;

    queue<pair<int, int>> q;
    q.emplace(src, 0);

    while(!q.empty()){

        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(now == 0){
            return cnt;
        }

        for(int i = max(0, k - (n - now)); i <= min(k, now); i++){
            int next = now - i + k - i;
            if(!visited[next]){
                visited[next] = true;
                q.emplace(next, cnt + 1);
            }
        }

    }

    return -1;

}

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    string str;
    cin >> str;

    int src = 0;

    for(auto& c : str){
        if(c == 'H'){
            src++;
        }
    }

    cout << bfs(src, n, k);

    return 0;

}