#include <iostream>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int dijkstra(vector<vector<int>>& arr){

    int n = arr.size();
    int m = arr[0].size();

    if(arr[0][0] == -1 or arr[n - 1][m - 1] == -1){
        return -1;
    }

    vector<vector<int>> distance(n, vector<int>(m, 987654321));
    distance[0][0] = arr[0][0];

    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push(make_pair(-arr[0][0], make_pair(0, 0)));

    while(!pq.empty()){
        int now_r = pq.top().second.first;
        int now_c = pq.top().second.second;
        int dist = -pq.top().first;
        pq.pop();
        if(distance[now_r][now_c] < dist){
            continue;
        }
        for(int i = 0; i < 4; i++){
            int next_r = now_r + dr[i];
            int next_c = now_c + dc[i];
            if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= m or arr[next_r][next_c] == -1){
                continue;
            }
            int cost = dist + arr[next_r][next_c];
            if(distance[next_r][next_c] > cost){
                distance[next_r][next_c] = cost;
                pq.push(make_pair(-cost, make_pair(next_r, next_c)));
            }
        }
    }

    if(distance[n - 1][m - 1] == 987654321){
        return -1;
    }

    return distance[n - 1][m - 1];

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    cout << dijkstra(arr);

    return 0;
}