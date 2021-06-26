#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<string>& map, vector<vector<vector<int>>>& dp, int now, int visited, int price){
	
	int n = dp.size();
	int& ret = dp[now][visited][price];
	
	if(ret != 0){
		return ret;
	}
	
	if(visited == (1 << n) - 1){
		return ret = 1;
	}
	
	ret = 1;
	
	for(int next = 0; next < n; next++){
		
		int next_price = map[now][next] - '0';
		
		if(next == now or (visited & (1 << next))){
			continue;
		}
		
		if(next_price >= price){
			ret = max(ret, dfs(map, dp, next, visited | (1 << next), next_price) + 1);
		}
	}
	return ret;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<string> map(n);
	for(int i = 0; i < n; i++){
		cin >> map[i];
	}
	
	vector<vector<vector<int>>> dp(n, vector<vector<int>>(1 << (n + 1), vector<int>(10)));
	
	cout << dfs(map, dp, 0, 1, 0);
	
	return 0;
}