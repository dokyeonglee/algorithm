#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
using ll = long long;

constexpr int INF = 1e9 + 1;

vector<int> dijkstra(const vector<vector<pair<int, int>>>& adj, int start) {

    vector<int> distance(adj.size(), INF);
    distance[start] = 0;

    priority_queue<pair<int, int>> pq;
    pq.emplace(0, start);

    while (!pq.empty()) {
        int now = pq.top().second;
        int dist = -pq.top().first;
        pq.pop();

        if (dist > distance[now]) {
            continue;
        }

        for (auto& e : adj[now]) {
            int next = e.first;
            int cost = e.second + dist;

            if (cost < distance[next]) {
                distance[next] = cost;
                pq.emplace(-cost, next);
            }
        }
    }

    return distance;
}

int find_cheapest_accessible_store(const vector<int>& distance, const vector<int>& store) {

    int cheapest_store = 0;
    int cheapest_price = INF;

    for (int i = 1; i < store.size(); ++i) {
        if (distance[i] != INF && store[i] <    cheapest_price) {
            cheapest_price = store[i];
            cheapest_store = i;
        }
    }

    return cheapest_store;
}

ll compute_min_lunch_trip(const vector<vector<pair<int, int>>>& adj, const vector<int>& restaurant_prices, const vector<int>& cafe_prices) {

    auto distance_from_home = dijkstra(adj, 1);
    int cheapest_accessible_restaurant = find_cheapest_accessible_store(distance_from_home, restaurant_prices);
    auto distance_from_restaurant = dijkstra(adj, cheapest_accessible_restaurant);
    int cheapest_cafe = find_cheapest_accessible_store(distance_from_restaurant, cafe_prices);

    return (ll)distance_from_home[cheapest_accessible_restaurant] + distance_from_restaurant[cheapest_cafe] + distance_from_home[cheapest_cafe];
}

void read_store_prices(vector<int>& store_prices) {
    for (int i = 1; i < store_prices.size(); ++i) {
        cin >> store_prices[i];
        if (store_prices[i] == 0) {
            store_prices[i] = INF;
        }
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> restaurant_prices(n + 1);
    read_store_prices(restaurant_prices);

    vector<int> cafe_prices(n + 1);
    read_store_prices(cafe_prices);
    
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].emplace_back(v, c);
        adj[v].emplace_back(u, c);
    }

    cout << compute_min_lunch_trip(adj, restaurant_prices, cafe_prices) << '\n';

    return 0;
}