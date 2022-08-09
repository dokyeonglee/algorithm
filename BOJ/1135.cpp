#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(vector<vector<int>>& tree, vector<int>& dp, int now){
	
	int& ret = dp[now];
	
	if(ret != -1){
		return ret;
	}
	
	if(tree[now].size() == 0){
		return ret = 0;
	}
	
	vector<int> cost(tree[now].size());
	for(int i = 0; i < tree[now].size(); i++){
		cost[i] = dfs(tree, dp, tree[now][i]);
	}
	
	sort(cost.begin(), cost.end(), greater<int>());
	
	for(int i = 0; i < cost.size(); i++){
		ret = max(ret, cost[i] + i + 1);
	}
	
	return ret;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<vector<int>> tree(n + 1);
	vector<int> dp(n + 1, -1);
	
	int p;
	cin >> p;
	
	for(int i = 1; i < n; i++){
		cin >> p;
		tree[p].push_back(i);
	}
	
	cout << dfs(tree, dp, 0);
	
	return 0;
}