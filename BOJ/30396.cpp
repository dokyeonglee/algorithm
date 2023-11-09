#include <iostream>
#include <queue>

using namespace std;

int dr[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dc[] = {1, 2, 2, 1, -1, -2, -2, -1};

int bfs(vector<string>& arr, int dst){

    queue<pair<int, int>> q;
    vector<bool> visited(1 << 16);

    int src = 0;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            src = (src << 1) | (arr[i][j] - '0');
        }
    }

    visited[src] = true;
    q.emplace(src, 0);

    while(!q.empty()){

        int now_knight = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(now_knight == dst){
            return cnt;
        }

        for(int i = 0; i < 16; i++){

            if(now_knight & (1 << i)){

                int now_r = i / 4;
                int now_c = i % 4;

                for(int j = 0; j < 8; j++){

                    int next_r = now_r + dr[j];
                    int next_c = now_c + dc[j];

                    if(next_r < 0 or next_r >= 4 or next_c < 0 or next_c >= 4 or (now_knight & (1 << (next_r * 4 + next_c)))){
                        continue;
                    }

                    int next_knight = (now_knight | (1 << (next_r * 4 + next_c))) & ~(1 << (now_r * 4 + now_c));

                    if(!visited[next_knight]){
                        visited[next_knight] = true;
                        q.emplace(next_knight, cnt + 1);
                    }

                }

            }
        }

    }

    return -1;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<string> arr(4);

    for(int i = 0; i < 4; i++){
        cin >> arr[i];
    }

    int dst = 0;
    for(int i = 0; i < 4; i++){
        string str;
        cin >> str;
        for(int j = 0; j < 4; j++){
            dst = (dst << 1) | (str[j] - '0');
        }
    }

    cout << bfs(arr, dst);

    return 0;
}