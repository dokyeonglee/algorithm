#include <iostream>
#include <vector>

using namespace std;

int solve(vector<pair<int, int>>& arr, vector<vector<int>>& adj, vector<int>& dp, int bit, int round){
	
	if(round == arr.size()){
		return 0;
	}
	
	int& ret = dp[bit];
	if(ret != -1){
		return ret;
	}
	
	ret = 0;
	for(int i = 0; i < arr.size(); i++){
		if((bit & (1 << i)) == 0){
			for(int j = 0; j < adj[i].size(); j++){
				if((bit & (1 << adj[i][j])) == 0){
					ret = max(ret, (round + 1) * arr[adj[i][j]].second + solve(arr, adj, dp, bit | (1 << adj[i][j]), round + 1));
					break;
				}
			}
		}
	}
	
	return ret;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<pair<int, int>> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i].first >> arr[i].second;
	}
	
	vector<vector<int>> adj(n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(arr[j].first % arr[i].first == 0){
				adj[j].push_back(i);
			}
		}
	}
	
	vector<int> dp(1 << n, -1);
	
	cout << solve(arr, adj, dp, 0, 0);
	
	return 0;
}