#include <iostream>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

vector<vector<int>> bfs(vector<pair<int, int>>& store, int n, int m){
        
    vector<vector<int>> distance(n + 1, vector<int>(m + 1, -1));

    queue<pair<int, int>> q;
    
    for(auto& s : store){
        q.push(s);
        distance[s.first][s.second] = 0;
    }

    while(!q.empty()){

        auto now = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){

            int next_r = now.first + dr[i];
            int next_c = now.second + dc[i];

            if(next_r < 1 or next_r > n or next_c < 1 or next_c > m){
                continue;
            }

            if(distance[next_r][next_c] == -1){
                distance[next_r][next_c] = distance[now.first][now.second] + 1;
                q.emplace(next_r, next_c);
            }

        }
    }

    return distance;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, r, c;
    cin >> n >> m >> r >> c;

    vector<pair<int, pair<int, int>>> room(r);
    for(auto& r : room){
        cin >> r.second.first >> r.second.second >> r.first;
    }

    vector<pair<int, int>> store(c);
    for(auto& s : store){
        cin >> s.first >> s.second;
    }

    auto distance = bfs(store, n, m);

    long long answer = 1e18;

    for(auto& r : room){
        answer = min(answer, (long long)distance[r.second.first][r.second.second] * r.first);
    }

    cout << answer;

    return 0;
}