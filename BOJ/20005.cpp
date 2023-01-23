#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

vector<vector<int>> bfs(vector<string>& arr, pair<int, int>& src){

    vector<vector<bool>> visited(arr.size(), vector<bool>(arr[0].size()));
    visited[src.first][src.second] = true;

    queue<pair<int, pair<int, int>>> q;
    q.push(make_pair(0, src));

    vector<vector<int>> distance(arr.size(), vector<int>(arr[0].size()));

    while(!q.empty()){

        int cnt = q.front().first;
        auto now = q.front().second;
        q.pop();

        distance[now.first][now.second] = cnt;

        for(int i = 0; i < 4; i++){
            int next_r = now.first + dr[i];
            int next_c = now.second + dc[i];
            if(next_r < 0 or next_r >= arr.size() or next_c < 0 or next_c >= arr[0].size()){
                continue;
            }
            if(!visited[next_r][next_c] and arr[next_r][next_c] != 'X'){
                visited[next_r][next_c] = true;
                q.push(make_pair(cnt + 1, make_pair(next_r, next_c)));
            }
        }
    }

    return distance;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, p;
    cin >> n >> m >> p;

    vector<string> arr(n);
    pair<int, int> boss;
    vector<pair<int, int>> pos(26);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 'B'){
                boss = make_pair(i, j);
            }else if(arr[i][j] >= 'a' and arr[i][j] <= 'z'){
                pos[arr[i][j] - 'a'] = make_pair(i, j);
            }
        }
    }

    vector<int> dps(26);
    for(int i = 0; i < p; i++){
        char c;
        int x;
        cin >> c >> x;
        dps[c - 'a'] = x;
    }

    int hp;
    cin >> hp;

    auto distance = bfs(arr, boss);

    vector <pair<int, int>> players(1);

    for(int i = 0; i < 26; i++){
        if(dps[i]){
            players.push_back(make_pair(distance[pos[i].first][pos[i].second] - 1, dps[i]));
        }
    }

    sort(players.begin() + 1, players.end());

    vector<int> psum(p + 1);
    for(int i = 1; i <= p; i++){
        psum[i] = psum[i - 1] + players[i].second;
    }

    int damage = 0;
    int idx = 1;

    while(idx <= p){
        damage += (players[idx].first - players[idx - 1].first) * psum[idx - 1];
        if(damage >= hp){
            break;
        }
        idx++;
    }

    cout << idx - 1;
    
    return 0;
}