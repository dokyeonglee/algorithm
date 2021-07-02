#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfs(int src, int dst){
	
	vector<bool> visited(1000001, false);
	visited[src] = true;
	
	queue<pair<int, int>> q;
	q.push(make_pair(0, src));
	
	vector<int> prev(1000001, -1);
	
	while(!q.empty()){
		
		int cnt = q.front().first;
		int now = q.front().second;
		q.pop();
		
		if(now == dst){
			break;		
		}
		
		if(now + 1 < 1000001 and !visited[now + 1]){
			prev[now + 1] = now;
			visited[now + 1] = true;
			q.push(make_pair(cnt + 1, now + 1));
		}
		
		if(now - 1 >= 0 and !visited[now - 1]){
			prev[now - 1] = now;
			visited[now - 1] = true;
			q.push(make_pair(cnt + 1, now - 1));
		}
		
		if(now * 2 < 1000001 and !visited[now * 2]){
			prev[now * 2] = now;
			visited[now * 2] = true;
			q.push(make_pair(cnt + 1, now * 2));
		}
	}
	
	return prev;
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;		
	cin >> n >> k;
	
	vector<int> prev = bfs(n, k);
	vector<int> path;
	
	int idx = k;
	
	while(idx != n){
		path.push_back(idx);
		idx = prev[idx];
	}
	path.push_back(n);
	
	cout << path.size() - 1 << "\n";
	for(int i = path.size() - 1; i >= 0; i--){
		cout << path[i] << " ";	
	}
	
	return 0;
}