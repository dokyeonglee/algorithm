#include <iostream>
#include <queue>

using namespace std;

int dr[] = {0, -1, 0, 1, 0};
int dc[] = {0, 0, 1, 0, -1};

int bfs(vector<string>& arr, pair<int, int>& src, pair<int, int>& dst, int k, int c){

    int n = arr.size();
    int m = arr[0].size();

    vector<vector<vector<int>>> distance(n, vector<vector<int>>(m, vector<int>(101, -1)));
    distance[src.first][src.second][0] = 0;

    queue<pair<int, pair<int, int>>> q;
    q.emplace(0, src);

    while(!q.empty()){
        int discomfort = q.front().first;
        auto now = q.front().second;
        q.pop();
        if(now == dst){
            return distance[now.first][now.second][discomfort];
        }
        for(int i = 0; i < 5; i++){
            int next_r = now.first + dr[i];
            int next_c = now.second + dc[i];
            if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= m or arr[next_r][next_c] == '#'){
                continue;
            }
            int next_discomfort = discomfort;
            if(arr[next_r][next_c] == '.'){
                next_discomfort = min(100, discomfort + c);
            }else{
                next_discomfort = max(0, discomfort - k);
            }
            if(next_discomfort < 100 and distance[next_r][next_c][next_discomfort] == -1){
                distance[next_r][next_c][next_discomfort] = distance[now.first][now.second][discomfort] + 1;
                q.emplace(next_discomfort, make_pair(next_r, next_c));
            }
        }
    }

    return -1;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int k, c;
    cin >> k >> c;

    vector<string> arr(n);

    pair<int, int> src, dst;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 'S'){
                src = make_pair(i, j);
            }else if(arr[i][j] == 'E'){
                arr[i][j] = '.';
                dst = make_pair(i, j);
            }
        }
    }

    cout << bfs(arr, src, dst, k, c);

    return 0;
}