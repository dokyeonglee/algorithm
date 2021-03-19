#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topology_sort(vector<vector<int>>& adj, vector<int>& in_degree, vector<int>& build_time){
	
	queue<int> q;
	vector<int> result(adj.size());
	
	for(int i = 1; i < adj.size(); i++){
		if(in_degree[i] == 0){
			q.push(i);
			result[i] = build_time[i];
		}
	}
	
	while(!q.empty()){
		
		int now = q.front();
		q.pop();
		
		for(int next : adj[now]){
			
			result[next] = max(result[next], result[now] + build_time[next]);
			
			if(--in_degree[next] == 0){
				q.push(next);
			}
			
		}
		
	}
	
	return result;
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> in_degree(n + 1);
	vector<int> build_time(n + 1);
	vector<vector<int>> adj(n + 1);
	
	for(int i = 1; i <= n; i++){
		
		cin >> build_time[i];
		
		while(1){
			int num;
			cin >> num;
			if(num == -1){
				break;
			}
			adj[num].push_back(i);
			in_degree[i]++;
		}
	}
	
	vector<int> answer = topology_sort(adj, in_degree, build_time);
	for(int i = 1; i <= n; i++){
		cout << answer[i] << '\n';
	}
	
	return 0;
}