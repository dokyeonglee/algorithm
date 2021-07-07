#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

vector<int> dfs(vector<int>& rice_cake){
	
	int n = rice_cake.size();
	
	vector<vector<bool>> visited(10, vector<bool>(n));
	
	stack<pair<int, int>> s;
	
	for(int i = 1; i <= 9; i++){
		if(rice_cake[0] & (1 << i)){
			visited[i][0] = true;
			s.push(make_pair(i, 0));
		}
	}
	
	vector<int> result(n, -1);
	
	while(!s.empty()){
		
		int now = s.top().first;
		int d = s.top().second;
		s.pop();
		
		result[d] = now;
		
		if(d == n - 1){
			result[d] = now;
			break;
		}
		
		for(int i = 1; i <= 9; i++){
			if(d < n - 1 and rice_cake[d + 1] & (1 << i) and now != i){
				if(!visited[i][d + 1]){
					result[d + 1] = i;
					visited[i][d + 1] = true;
					s.push(make_pair(i, d + 1));	
				}
				
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
	
	vector<int> rice_cake(n);
	
	for(int i = 0; i < n; i++){
		int m;
		cin >> m;
		for(int j = 0; j < m; j++){
			int a;
			cin >> a;
			rice_cake[i] |= (1 << a);
		}
	}
	
	vector<int> result = dfs(rice_cake);
	
	if(result.back() == -1){
		cout << -1;
	}else{
		for(int i = 0; i < n; i++){
			cout << result[i] << "\n";
		}
	}
	
	return 0;
}