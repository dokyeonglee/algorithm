#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

double dist(pair<int, int> a, pair<int, int> b){
	return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

double solve(vector<vector<double>>& graph, vector<vector<double>>& dp, int bit, int now){
	if(bit == (1 << graph.size()) - 1){
		return graph[now][0];
	}
	double& ret = dp[bit][now];
	if(ret != -1){
		return ret;
	}
	ret = 1e18;
	for(int i = 0; i < graph.size(); i++){
		if((bit & (1 << i)) == 0){
			ret = min(ret, graph[now][i] + solve(graph, dp, bit | (1 << i), i));
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
	
	vector<vector<double>> graph(n, vector<double>(n));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			graph[i][j] = dist(arr[i], arr[j]);
		}
	}
	
	vector<vector<double>> dp(1 << n, vector<double>(n, -1));
	
	cout << fixed;
	cout << setprecision(8);
	cout << solve(graph, dp, 1, 0);
	
	return 0;
}