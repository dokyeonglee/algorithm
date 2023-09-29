#include <iostream>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

long long dijkstra(vector<vector<int>>& arr, int src, int dst){

    int n = arr.size();
    int m = arr[0].size();

    vector<vector<long long>> distance(n * m, vector<long long>(3, 1e18));
    distance[src][1] = 0;

    priority_queue<pair<pair<int, int>, int>> pq;
    pq.push(make_pair(make_pair(0, src), 1));

    while(!pq.empty()){

        int now = pq.top().first.second;
        int dist = -pq.top().first.first;
        int move = pq.top().second;
        pq.pop();

        if(distance[now][move] < dist){
			continue;
		}

		for(int i = move / 2; i < 4; i += 2 - (move == 0)){

			int next_r = now / m + dr[i];
            int next_c = now % m + dc[i];

            if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= m or arr[next_r][next_c] == -1){
                continue;
            }

			int cost = arr[next_r][next_c] + dist;
			
			if(distance[next_r * m + next_c][(move + 1) % 3] > cost){
				pq.push(make_pair(make_pair(-cost, next_r * m + next_c), (move + 1) % 3));
				distance[next_r * m + next_c][(move + 1) % 3] = cost;
			}
		}
	}

    long long result = min(distance[dst][0], min(distance[dst][1], distance[dst][2]));

    if(result == 1e18){
        return -1;
    }

    return result;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int src_row, src_col, dst_row, dst_col;
    cin >> src_row >> src_col >> dst_row >> dst_col;

    src_row--;
    src_col--;
    dst_row--;
    dst_col--;

    vector<vector<int>> arr(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    cout << dijkstra(arr, src_row * m + src_col, dst_row * m + dst_col);

    return 0;
}