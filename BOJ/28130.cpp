#include <iostream>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int bfs(vector<string>& board, pair<int, int>& src, pair<int, int>& dst){

    int n = board.size();
    int m = board[0].size();

    vector<vector<int>> sanghyeok(n, vector<int>(m, 987654321));
    sanghyeok[src.first][src.second] = 0;

    vector<vector<int>> sunwoo(n, vector<int>(m));

    int r = dst.first;
    int c = dst.second;

    for(int i = 0; i < 2 * (n + m - 2); i++){
        sunwoo[r][c] = i;
        if(r == 0 and c != m - 1){
            c++;
        }else if(r != n - 1 and c == m - 1){
            r++;
        }else if(r == n - 1 and c != 0){
            c--;
        }else if(r != 0 and c == 0){
            r--;
        }
    }

    queue<pair<int, int>> q;
    q.push(src);

    int result = 987654321;

    while(!q.empty()){
        auto now = q.front();
        q.pop();
        if(now.first == 0 or now.first == n - 1 or now.second == 0 or now.second == m - 1){
            if(sunwoo[now.first][now.second] > sanghyeok[now.first][now.second]){
                if((sunwoo[now.first][now.second] - sanghyeok[now.first][now.second]) % 2 == 0){
                    result = min(result, sunwoo[now.first][now.second]);
                }
            }else{
                if((sanghyeok[now.first][now.second] - sunwoo[now.first][now.second]) % (2 * (n + m - 2)) == 0){
                    result = min(result, sanghyeok[now.first][now.second]);
                }
            }
        }
        for(int i = 0; i < 4; i++){
            int next_r = now.first + dr[i];
            int next_c = now.second + dc[i];
            if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= m){
                continue;
            }
            if(sanghyeok[next_r][next_c] == 987654321 and board[next_r][next_c] != 'G'){
                sanghyeok[next_r][next_c] = sanghyeok[now.first][now.second] + 1;
                q.push(make_pair(next_r, next_c));
            }
        }
    }

    if(result == 987654321){
        result = -1;
    }

    return result;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    
    vector<string> board(n);

    pair<int, int> src;
    pair<int, int> dst;

    for(int i = 0; i < n; i++){
        cin >> board[i];
        for(int j = 0; j < m; j++){
            if(board[i][j] == 'A'){
                src = make_pair(i, j);
            }else if(board[i][j] == 'B'){
                dst = make_pair(i, j);
            }
        }
    }

    cout << bfs(board, src, dst);

    return 0;
}