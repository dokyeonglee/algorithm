#include <iostream>
#include <queue>

using namespace std;

bool visited[1000001][2];

int bfs(int src, int dst){

    visited[src][0] = true;

    queue<pair<int, pair<int, int>>> q;
    q.emplace(make_pair(src, make_pair(0, 0)));

    while(!q.empty()){

        int now = q.front().first;
        int cnt = q.front().second.first;
        int chance = q.front().second.second;
        q.pop();

        if(now == dst){
            return cnt;
        }

        if(!visited[min(now + 1, dst)][chance]){
            visited[min(now + 1, dst)][chance] = true;
            q.emplace(min(now + 1, dst), make_pair(cnt + 1, chance));
        }

        if(now * 2 <= dst and !visited[now * 2][chance]){
            visited[now * 2][chance] = true;
            q.emplace(now * 2, make_pair(cnt + 1, chance));
        }

        if(now * 10 <= dst and chance == 0 and !visited[now * 10][1]){
            visited[now * 10][1] = true;
            q.emplace(now * 10, make_pair(cnt + 1, 1));
        }
    }

    return -1;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    cout << bfs(a, b);

    return 0;
}