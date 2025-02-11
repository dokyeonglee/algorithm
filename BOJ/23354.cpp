#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

vector<vector<int>> dijkstra(vector<vector<int>>& arr, pair<int, int>& src){

    vector<vector<int>> distance(arr.size(), vector<int>(arr[0].size(), 1e8));
    distance[src.first][src.second] = 0;

    priority_queue<pair<int, pair<int, int>>> pq;
    pq.emplace(0, src);

    while(!pq.empty()){
        auto now = pq.top().second;
        int dist = -pq.top().first;
        pq.pop();
        if(dist < distance[now.first][now.second]){
            continue;
        }
        for(int i = 0; i < 4; i++){
            int next_r = now.first + dr[i];
            int next_c = now.second + dc[i];
            if(next_r < 0 or next_r >= arr.size() or next_c < 0 or next_c >= arr[0].size()){
                continue;
            }
            int cost = dist + arr[next_r][next_c];
            if(cost < distance[next_r][next_c]){
                distance[next_r][next_c] = cost;
                pq.emplace(-cost, make_pair(next_r, next_c));
            }
        }
    }
    
    return distance;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));

    pair<int, int> base;
    vector<pair<int, int>> deserters;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            if(arr[i][j] == -1){
                base = make_pair(i, j);
                arr[i][j] = 0;
            }else if(arr[i][j] == 0){
                deserters.emplace_back(i, j);
            }
        }
    }

    if(deserters.size() == 0){
        cout << 0;
    }else{
        vector<vector<vector<int>>> distance_from_deserters(deserters.size());
        for(int i = 0; i < deserters.size(); i++){
            distance_from_deserters[i] = dijkstra(arr, deserters[i]);
        }
        vector<int> perm(deserters.size());
        for(int i = 0; i < perm.size(); i++){
            perm[i] = i;
        }
        int answer = 1e9;
        do{
            int result = distance_from_deserters[perm.front()][base.first][base.second] + distance_from_deserters[perm.back()][base.first][base.second];
            for(int i = 1; i < perm.size(); i++){
                auto p = deserters[perm[i - 1]];
                result += distance_from_deserters[perm[i]][p.first][p.second];
            }
            answer = min(answer, result);
        }while(next_permutation(perm.begin(), perm.end()));
        cout << answer << "\n";
    }

    return 0;

}