#include <iostream>
#include <queue>

using namespace std;

int bfs(int n, int a_src, int b_src){

    vector<int> visited(n + 1);
    
    queue<pair<int, pair<int, int>>> q;
    q.push(make_pair(0, make_pair(a_src, 1)));
    q.push(make_pair(0, make_pair(b_src, 1)));

    while(!q.empty()){

        int cnt = q.front().first;
        int now = q.front().second.first;
        int d = q.front().second.second;
        q.pop();

        for(int i = -1; i < 2; i += 2){
            int next = now + i * d;
            if(next < 1 or next > n){
                continue;
            }
            if(visited[next] == cnt + 1){
                return cnt + 1;
            }else{
                visited[next] = cnt + 1;
                q.push(make_pair(cnt + 1, make_pair(next, d * 2)));
            }
        }

    }

    return -1;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b;
    cin >> n >> a >> b;

    cout << bfs(n, a, b);

    return 0;
}