#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> graph(n + 1);
	vector<int> in_degree(n + m + 1);
	vector<int> idx(n + m + 1);
	
	for(int i = 1; i <= n; i++){
		idx[i] = i;
	}
	
	for(int i = 0; i < m; i++){
		
		int k;
		cin >> k;
		vector<int> temp(k);
		for(int j = 0; j < k; j++){
			cin >> temp[j];
		}
		
		int r;
		cin >> r;
		
		if(in_degree[r]){
			idx[++n] = r;
			r = n;
		}
		for(int j = 0; j < k; j++){
			graph[temp[j]].push_back(r);
			in_degree[r]++;
		}		
	}
	
	int l;
	cin >> l;
	
	int cnt = 0;
	vector<bool> answer(n + 1);
	queue<int> q;
	
	answer.reserve(n + 1);
	
	for(int i = 0; i < l; i++){
		int x;
		cin >> x;
		q.push(x);
	}
	
	while(!q.empty()){
		int now = idx[q.front()];
		q.pop();
		if(answer[now]) continue;
		answer[now] = true;
		cnt++;
		for(int next : graph[now]){
			if(--in_degree[next] == 0){
				q.push(next);
			}
		}
	}
	
	cout << cnt << "\n";

	for(int i = 1; i <= n; i++){
		if(answer[i]){
			cout << i << " ";
		}
	}
	
	return 0;
}