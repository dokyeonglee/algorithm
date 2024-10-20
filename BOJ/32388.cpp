#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

double get_distance(pair<double, double>& a, pair<double, double>& b){
    return sqrtl((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

double dijkstra(vector<vector<double>>& graph){

    vector<double> distance(graph.size(), 1e18);
    distance[graph.size() - 2] = 0;

    priority_queue<pair<double, int>> pq;
    pq.emplace(0, graph.size() - 2);

    while(!pq.empty()){

        int now = pq.top().second;
        double dist = -pq.top().first;
        pq.pop();

        if(distance[now] < dist){
            continue;
        }

        for(int next = 0; next < graph[now].size(); next++){
            double cost = dist + graph[now][next];
            if(distance[next] > cost){
                pq.emplace(-cost, next);
                distance[next] = cost;
            }
        }

    }

    return distance.back();

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    pair<double, double> src;
    pair<double, double> dst;

    cin >> src.first >> src.second;
    cin >> dst.first >> dst.second;

    int n;
    cin >> n;

    vector<pair<double, double>> arr(n);

    for(auto& a : arr){
        cin >> a.first >> a.second;
    }

    arr.push_back(src);
    arr.push_back(dst);

    vector<vector<double>> graph(n + 2, vector<double>(n + 2));

    for(int i = 0; i < graph.size(); i++){
        for(int j = 0; j < graph[0].size(); j++){
            graph[i][j] = get_distance(arr[i], arr[j]) / 5;
            if(i < n){
                graph[i][j] = min(graph[i][j], abs(graph[i][j] - 10) + 2);
            }
        }
    }

    cout << fixed;
    cout.precision(10);
    cout << dijkstra(graph);

    return 0;
}