#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>>& adj, int src){
	
	vector<int> distance(adj.size(), 987654321);
	distance[src] = 0;
	
	priority_queue<pair<int, int>> pq;
	pq.emplace(0, src);
	
	while(!pq.empty()){
		
		int now = pq.top().second;
		int dist = -pq.top().first;
		pq.pop();
		
		if(distance[now] < dist){
			continue;
		}
		
		for(auto e : adj[now]){

			int next = e.first;
			int cost = e.second + dist;
			
			if(distance[next] > cost){
				pq.emplace(-cost, next);
				distance[next] = cost;
			}
		}
	}

    return distance;
	
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, v, e;
    cin >> n >> v >> e;

    int a, b;
    cin >> a >> b;

    vector<int> home(n);
    for(int& h : home){
        cin >> h;
    }

    vector<vector<pair<int, int>>> adj(v + 1);
    for(int i = 0; i < e; i++){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].emplace_back(v, c);
        adj[v].emplace_back(u, c);
    }

    vector<int> distance1 = dijkstra(adj, a);
    vector<int> distance2 = dijkstra(adj, b);

    long long answer = 0;

    for(int& h : home){
        if(distance1[h] == 987654321){
            distance1[h] = -1;
        }
        if(distance2[h] == 987654321){
            distance2[h] = -1;
        }
        answer += distance1[h] + distance2[h];
    }

    cout << answer;

    return 0;
}