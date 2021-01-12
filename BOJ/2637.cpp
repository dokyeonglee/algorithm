#include <iostream>
#include <vector>
#include <queue>


using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n , m;
	cin >> n >> m;
	
	vector<int> indegree(n + 1);
	vector<vector<vector<int>>> parts(n + 1);
	
	for(int i = 0; i < m; i++){
		int p1, p2, amount;
		cin >> p1 >> p2 >> amount;
		parts[p2].push_back({p1, amount});
		indegree[p1]++;
	}
	
	vector<vector<int>> result(n + 1, vector<int>(n + 1));
	
	queue<int> q;
	for(int i = 1; i <= n; i++){
		if(indegree[i] == 0){
			q.push(i);
			result[i][i] = 1;
		}	
	}
	
	while(!q.empty()){
		
		int now = q.front();
		q.pop();
		
		for(vector<int> v : parts[now]){
			
			int next = v[0];
			int amount = v[1];
			
			for(int i = 1; i <= n; i++){
				result[next][i] += result[now][i] * amount;
			}
			
			if(--indegree[next] == 0){
				q.push(next);
			}
		}
	}
	
	for(int i = 1; i < n; i++){
		if(result[n][i] != 0){
			cout << i << " " << result[n][i] << endl;	
		}
	}
	
	return 0;
}