#include <iostream>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

pair<int, int> dijkstra(vector<string>& arr, vector<vector<int>>& cnt, pair<int, int>& src, pair<int, int>& dst){

    int n = arr.size();
    int m = arr[0].size();

    vector<vector<pair<int, int>>> distance(n, vector<pair<int, int>>(m, pair<int, int>(987654321, 987654321)));
    distance[src.first][src.second] = make_pair(0, cnt[src.first][src.second]);

    priority_queue<pair<pair<int, int>, pair<int, int>>, vector<pair<pair<int, int>, pair<int, int>>>, greater<pair<pair<int, int>, pair<int, int>>>> pq;
    pq.push(make_pair(distance[src.first][src.second], src));

    while(!pq.empty()){

        auto dist = pq.top().first;
        auto now = pq.top().second;
        pq.pop();

        if(distance[now.first][now.second] < dist){
            continue;
        }

        for(int i = 0; i < 4; i++){

            int next_r = now.first + dr[i];
            int next_c = now.second + dc[i];

            if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= m){
                continue;
            }

            pair<int, int> cost = dist;
            cost.first += arr[next_r][next_c] == 'g';
            cost.second += cnt[next_r][next_c];

            if(distance[next_r][next_c] > cost){
                pq.push(make_pair(cost, make_pair(next_r, next_c)));
                distance[next_r][next_c] = cost;
            }
        }
    }

    return distance[dst.first][dst.second];
    
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    
    vector<string> arr(n);
    pair<int, int> src, dst;

    vector<vector<int>> cnt(n, vector<int>(m));

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 'F'){
                dst = make_pair(i, j);
            }else if(arr[i][j] == 'S'){
                src = make_pair(i, j);
            }else if(arr[i][j] == 'g'){
                for(int k = 0; k < 4; k++){
                    int next_r = i + dr[k];
                    int next_c = j + dc[k];
                    if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= m){
                        continue;
                    }
                    if(arr[next_r][next_c] == '.'){
                        cnt[next_r][next_c] = 1;
                    }
                }
            }
        }
    }

    cnt[dst.first][dst.second] = 0;

    pair<int, int> answer = dijkstra(arr, cnt, src, dst);

    cout << answer.first << " " << answer.second;

    return 0;
}