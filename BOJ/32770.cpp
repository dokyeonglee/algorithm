#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

long long dijkstra(vector<vector<pair<int, int>>>& adj, int src, int dst){

    vector<long long> distance(adj.size(), 1e18);
    distance[src] = 0;

    priority_queue<pair<long long, int>> pq;
    pq.emplace(0ll, src);

    while(!pq.empty()){

        int now = pq.top().second;
        long long dist = -pq.top().first;
        pq.pop();

        if(now == dst) break;

        if(dist > distance[now]){
            continue;
        }

        for(auto& e : adj[now]){
            int next = e.first;
            long long cost = dist + e.second;
            if(cost < distance[next]){
                distance[next] = cost;
                pq.emplace(-cost, next);
            }
        }

    }

    return distance[dst];

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    unordered_map<string, int> station_name_to_num;

    int e;
    cin >> e;

    vector<vector<pair<int, int>>> adj(420001);

    int number_of_station = 0;

    while(e--){

        string station1, station2;
        int c;

        cin >> station1 >> station2;
        cin >> c;

        if(station_name_to_num.count(station1) == 0){
            station_name_to_num[station1] = ++number_of_station;
        }

        if(station_name_to_num.count(station2) == 0){
            station_name_to_num[station2] = ++number_of_station;
        }

        int u = station_name_to_num[station1];
        int v = station_name_to_num[station2];

        adj[u].emplace_back(v, c);

    }

    adj.resize(number_of_station + 1);

    int home = station_name_to_num["home"];
    int school = station_name_to_num["sasa"];

    auto school_to_home = dijkstra(adj, school, home);
    auto home_to_school = dijkstra(adj, home, school);

    if(school_to_home == 1e18 or home_to_school == 1e18){
        cout << -1;
    }else{
        cout << school_to_home + home_to_school;
    }

    return 0;
}