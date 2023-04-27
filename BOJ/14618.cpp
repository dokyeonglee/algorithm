#include <iostream>
#include <queue>

using namespace std;

int dijkstra(vector<vector<pair<int, int>>>& graph, vector<int>& src, int dst){
	
	vector<int> distance(graph.size(), 987654321);
	priority_queue<pair<int, int>> pq;

	for(int i = 0; i < src.size(); i++){
        distance[src[i]] = 0;
        pq.push(make_pair(0, src[i]));
    }
	
	while(!pq.empty()){
		
		int now = pq.top().second;
		int dist = -pq.top().first;
		pq.pop();
		
		if(distance[now] < dist){
			continue;
		}
		
		for(auto e : graph[now]){
			
			int next = e.first;
			int cost = e.second + dist;
			
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

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n + 1);

    int dst;
    cin >> dst;

    int k;
    cin >> k;

    vector<int> A(k);
    vector<int> B(k);

    for(int i = 0; i < k; i++){
        cin >> A[i];
    }

    for(int i = 0; i < k; i++){
        cin >> B[i];
    }

    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        graph[u].push_back(make_pair(v, c));
        graph[v].push_back(make_pair(u, c));
    }

    int answer = dijkstra(graph, A, dst);
    int answer2 = dijkstra(graph, B, dst);

    if(min(answer, answer2) == 987654321){
        cout << -1;
    }else if(answer > answer2){
        cout << "B\n";
        cout << answer2; 
    }else{
        cout << "A\n";
        cout << answer;
    }

    return 0;
}