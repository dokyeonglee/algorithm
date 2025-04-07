#include <iostream>
#include <queue>

using namespace std;

int click[] = {0x1A0, 0x1D0, 0x0C8, 0x134, 0x0BA, 0x059, 0x026, 0x017, 0x00B};

int bfs(int src, int dst){

    vector<bool> visited(1 << 9);
    visited[src] = true;

    queue<pair<int, int>> q;
    q.emplace(src, 0);

    while(!q.empty()){
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(now == dst){
            return cnt;
        }
        for(int i = 0; i < 9; i++){
            int next = (now ^ click[i]);
            if(!visited[next]){
                visited[next] = true;
                q.emplace(next, cnt + 1);
            }
        }
    }

    return -1;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){

        int src = 0;
        int dst = 0;

        for(int i = 0; i < 3; i++){
            string str;
            cin >> str;
            dst <<= 3;
            for(int j = 0; j < 3; j++){
                if(str[j] == '*'){
                    dst |= (1 << j);
                }
            }
        }

        cout << bfs(src, dst) << "\n";

    }

    return 0;

}