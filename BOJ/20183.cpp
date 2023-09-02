#include <iostream>
#include <queue>

using namespace std;

long long dijkstra(vector<vector<pair<int, int>>>& adj, int src, int dst, int max_cost){

    vector<long long> distance(adj.size(), 1e18);
    distance[src] = 0;

    priority_queue<pair<long long, int>> pq;
    pq.push(make_pair(0, src));

    while(!pq.empty()){

        int now = pq.top().second;
        long long dist = -pq.top().first;
        pq.pop();

        if(distance[now] < dist){
			continue;
		}
		
		for(auto e : adj[now]){

            if(e.second > max_cost){
                continue;
            }
			
			int next = e.first;
			long long cost = e.second + dist;
			
			if(distance[next] > cost){
				pq.push(make_pair(-cost, next));
				distance[next] = cost;
			}
		}
	}

    return distance[dst];

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, m, src, dst, budget;
    cin >> n >> m >> src >> dst >> budget;

    vector<vector<pair<int, int>>> adj(n + 1);
    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back(make_pair(v, c));
        adj[v].push_back(make_pair(u, c));
    }

    int answer = -1;
    int left = 1;
    int right = 1000000000;

    while(left <= right){
        
        int mid = (left + right) / 2;

        if(dijkstra(adj, src, dst, mid) <= budget){
            answer = mid;
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }

    cout << answer;

    return 0;
}