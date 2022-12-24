#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

pair<int, vector<pair<int, int>>> dijkstra(vector<vector<int>>& graph, pair<int, int>& src, pair<int, int>& dst, int k){
    
    int n = graph.size();

    vector<int> distance(n * n, 987654321);
    distance[src.first * n + src.second] = 0;

    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push(make_pair(0, src));

    vector<int> predecessor(n * n, -1);

    while(!pq.empty()){

        auto now = pq.top().second;
        int dist = -pq.top().first;
        pq.pop();

        if(distance[now.first * n + now.second] < dist){
            continue;
        }

        for(int i = 0; i < 4; i++){

            int next_r = now.first + dr[i];
            int next_c = now.second + dc[i];

            if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= n){
                continue;
            }

            int cost = dist + graph[next_r][next_c];

            if(distance[next_r * n + next_c] > cost){
                pq.push(make_pair(-cost, make_pair(next_r, next_c)));
                distance[next_r * n + next_c] = cost;
                predecessor[next_r * n + next_c] = now.first * n + now.second;
            }
        }
    }

    vector<pair<int ,int>> _result;
    pair<int, int> u = dst;

    _result.push_back(dst);

    while(u != src){
        auto p = predecessor[u.first * n + u.second];
        _result.push_back(make_pair(p / n, p % n));
        u = _result.back();
    }

    reverse(_result.begin(), _result.end());

    vector<pair<int, int>> result;
    result.push_back(src);

    for(int i = 1; i < _result.size(); i++){
        if(result.back().first != _result[i].first and result.back().second != _result[i].second){
            result.push_back(_result[i - 1]);
        }
    }

    result.push_back(dst);
    
    return make_pair(distance[dst.first * n + dst.second] + graph[src.first][src.second], result);

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n, 1));

    pair<int, int> src, dst;
    cin >> src.first >> src.second >> dst.first >> dst.second;

    src.first--;
    src.second--;
    dst.first--;
    dst.second--;

    int k;
    cin >> k;

    int m;
    cin >> m;

    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        pair<int, int> u, v;
        cin >> u.first >> u.second;
        for(int j = 1; j < x; j++){
            cin >> v.first >> v.second;
            if(u.first == v.first){
                for(int a = min(u.second, v.second); a <= max(u.second, v.second); a++){
                    graph[u.first - 1][a - 1] = k;
                }
            }else if(u.second == v.second){
                for(int a = min(u.first, v.first); a <= max(u.first, v.first); a++){
                    graph[a - 1][u.second - 1] = k;
                }
            }
            u = v;
        }
    }

    auto answer = dijkstra(graph, src, dst, k);
    cout << answer.first << endl;
    cout << answer.second.size();
    for(auto u : answer.second){
        cout << " " << u.first + 1 << " " << u.second + 1;
    }


    return 0;
}