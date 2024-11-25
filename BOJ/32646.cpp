#include <iostream>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

vector<vector<int>> dijkstra(vector<vector<int>>& arr, vector<vector<int>>& teleport, int max_teleport){

    int n = arr.size() - 1;
    int m = arr[0].size() - 1;

    vector<vector<vector<int>>> _distance(max_teleport + 1, vector<vector<int>>(n + 1, vector<int>(m + 1, 1e9)));
    _distance[0][1][1] = 0;

    priority_queue<pair<pair<int, int>, pair<int, int>>> pq;
    pq.emplace(make_pair(0, 0), make_pair(1, 1));

    while(!pq.empty()){

        int dist = -pq.top().first.first;
        int teleport_cnt = pq.top().first.second;
        auto now = pq.top().second;
        pq.pop();

        if(dist > _distance[teleport_cnt][now.first][now.second]){
            continue;
        }

        for(int i = 0; i < 4; i++){
            int next_r = now.first + dr[i];
            int next_c = now.second + dc[i];
            if(next_r < 1 or next_r > n or next_c < 1 or next_c > m){
                continue;
            }
            int cost = dist + arr[next_r][next_c];
            if(cost < _distance[teleport_cnt][next_r][next_c]){
                _distance[teleport_cnt][next_r][next_c] = cost;
                pq.emplace(make_pair(-cost, teleport_cnt), make_pair(next_r, next_c));
            }
        }

        if(teleport_cnt < max_teleport and teleport[now.first][now.second]){
            int next = teleport[now.first][now.second];
            if(dist < _distance[teleport_cnt + 1][next / m][next % m + 1]){
                _distance[teleport_cnt + 1][next / m][next % m + 1] = dist;
                pq.emplace(make_pair(-dist, teleport_cnt + 1), make_pair(next / m, next % m + 1));
            }
        }

    }

    vector<vector<int>> distance(n + 1, vector<int>(m + 1, 1e9));

    for(int i = 0; i <= max_teleport; i++){
        for(int r = 1; r <= n; r++){
            for(int c = 1; c <= m; c++){
                distance[r][c] = min(distance[r][c], _distance[i][r][c]);
            }
        }
    }

    return distance;

}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k, t, q;
    cin >> n >> m >> k >> t >> q;

    vector<vector<int>> arr(n + 1, vector<int>(m + 1));
    vector<vector<int>> teleport(arr);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> arr[i][j];
        }
    }

    while(k--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        teleport[x1][y1] = x2 * m + y2 - 1;
    }
    
    auto distance = dijkstra(arr, teleport, t);

    while(q--){
        int x, y, p;
        cin >> p >> x >> y;
        if(distance[x][y] <= p){
            cout << "1\n";
        }else{
            cout << "0\n";
        }
    }

    return 0;
}