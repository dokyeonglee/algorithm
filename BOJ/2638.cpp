#include <iostream>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void bfs(vector<vector<int>>& cheese, vector<vector<int>>& cnt, queue<pair<int, int>>& q){

    while(!q.empty()){
        auto now = q.front();
        q.pop();
        if(cheese[now.first][now.second] == 2){ 
            continue;
        }
        cheese[now.first][now.second] = 2;
        for(int i = 0; i < 4; i++){
            int next_r = now.first + dr[i];
            int next_c = now.second + dc[i];
            if(next_r < 0 or next_r >= cheese.size() or next_c < 0 or next_c >= cheese[0].size()){
                continue;
            }
            if(cheese[next_r][next_c] == 0){
                q.push(make_pair(next_r, next_c));
            }else if(cheese[next_r][next_c] == 1){
                cnt[next_r][next_c]++;
            }
        }
    }

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> cheese(n, vector<int>(m));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> cheese[i][j];
        }
    }

    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));

    int answer = 0;

    vector<vector<int>> cnt(n, vector<int>(m));

    while(!q.empty()){
        answer++;
        bfs(cheese, cnt, q);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(cheese[i][j] != 1){
                    continue;
                }
                if(cnt[i][j] >= 2){
                    cheese[i][j] = 0;
                    q.push(make_pair(i, j));
                }
            }
        }
    }

    cout << answer - 1;

    return 0;
}