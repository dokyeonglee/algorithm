#include <iostream>
#include <queue>

using namespace std;

pair<int, int> dijkstra(vector<vector<pair<int, pair<int, int>>>>& graph, vector<int>& arr, int src, int dst){
	
	vector<pair<int, int>> distance(graph.size(), pair<int, int>(987654321, 987654321));
	distance[src] = make_pair(0, 0);
	
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
	pq.push(make_pair(0, make_pair(0, 0)));
	
	while(!pq.empty()){
		
		int now = pq.top().first;
		auto dist = pq.top().second;
		pq.pop();
		
		if(distance[now] < dist){
			continue;
		}
		
		for(auto e : graph[now]){
			
			int next = e.first;
			auto cost = e.second;

            cost.first += dist.first;
            cost.second += dist.second;
			
			if(distance[next] > cost){
				pq.push(make_pair(next, cost));
				distance[next] = cost;
			}
		}
	}
	
	return distance[dst];
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<vector<pair<int, pair<int, int>>>> graph(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){

            int c;
            cin >> c;

            if(c != 0){
                graph[i].push_back(make_pair(j, make_pair(arr[i] != arr[j], c)));
            }
            
        }
    }

    auto answer = dijkstra(graph, arr, 0, m);
    cout << answer.first << " " << answer.second;

    return 0;
}