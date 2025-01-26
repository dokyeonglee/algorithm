#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int bfs(int src, int n){

    int sz = 2 * n;

    vector<bool> visited(1 << sz);
    visited[src] = true;

    queue<pair<int, int>> q;
    q.emplace(src, 0);

    while(!q.empty()){
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();
        int score = 0;
        for(int i = 0; i < sz; i += 2){
            if(now & (1 << i) and (now & (1 << (i + 1))) == 0){
                score++;
            }else if(now & (1 << (i + 1)) and (now & (1 << i)) == 0){
                score--;
            }
        }
        if(score > 0){
            return cnt;
        }
        for(int j = 1; j < 2 * n; j++){
            int next =  ((now >> (j + 1)) << (j + 1))
                        | (now & ((1 << j) - 1)) << 1
                        | (now & (1 << j)) >> j;
            if(now == next or visited[next]){
                continue;
            }
            visited[next] = true;
            q.emplace(next, cnt + 1);
        }
    }

    return -1;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int src = 0;

    for(int i = 0; i < 2 * n; i++){
        char c;
        cin >> c;
        if(c == 'O'){
            src |= (1 << i);
        }
    }

    cout << bfs(src, n);

    return 0;

}