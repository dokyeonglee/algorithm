#include <iostream>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int bfs(vector<string>& arr){

    int r = arr.size();
    int c = arr[0].size();

    vector<vector<int>> visited(r, vector<int>(c, 987654321));
    vector<vector<int>> fire_visited(r, vector<int>(c, 987654321));
    queue<pair<int, int>> q;
    queue<pair<int, int>> fire_q;

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(arr[i][j] == 'J'){ 
                arr[i][j] = '.';
                visited[i][j] = 0;
                q.push(make_pair(i, j));
            }else if(arr[i][j] == 'F'){
                fire_visited[i][j] = 0;
                fire_q.push(make_pair(i, j));
            }
        }
    }

    while(!fire_q.empty()){
        auto fire = fire_q.front();
        fire_q.pop();
        for(int i = 0; i < 4; i++){
            int next_fire_r = fire.first + dr[i];
            int next_fire_c = fire.second + dc[i];
            if(next_fire_r < 0 or next_fire_r >= r or next_fire_c < 0 or next_fire_c >= c){
                continue;
            }
            if(fire_visited[next_fire_r][next_fire_c] > fire_visited[fire.first][fire.second] + 1 and arr[next_fire_r][next_fire_c] == '.'){
                fire_visited[next_fire_r][next_fire_c] = fire_visited[fire.first][fire.second] + 1;
                fire_q.push(make_pair(next_fire_r, next_fire_c));
            }
        }
    }

    while(!q.empty()){

        auto now = q.front();
        q.pop();

        if(now.first == 0 or now.first == r - 1 or now.second == 0 or now.second == c - 1){
            return visited[now.first][now.second] + 1;
        }

        for(int i = 0; i < 4; i++){
            int next_r = now.first + dr[i];
            int next_c = now.second + dc[i];
            if(next_r < 0 or next_r >= r or next_c < 0 or next_c >= c){
                continue;
            }
            if(visited[next_r][next_c] == 987654321 and visited[now.first][now.second] + 1 < fire_visited[next_r][next_c] and arr[next_r][next_c] == '.'){
                visited[next_r][next_c] = visited[now.first][now.second] + 1;
                q.push(make_pair(next_r, next_c));
            }
        }

    }

    return -1;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int r, c;
    cin >> r >> c;

    vector<string> arr(r);
    for(int i = 0; i < r; i++){
        cin >> arr[i];
    }

    int answer = bfs(arr);

    if(answer == -1){
        cout << "IMPOSSIBLE";
    }else{
        cout << answer;
    }

    return 0;
}