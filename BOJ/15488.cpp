#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int dr[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dc[] = {2, 1, -1, -2, -2, -1, 1, 2};

double solve(vector<vector<vector<double>>>& dp, int r, int c, int k){

	if(r <= 0 or r >= dp.size() or c <= 0 or c >= dp.size()){
		return 0;
	}
	
	if(k == 0){
		return 1;
	}
	
	double& ret = dp[r][c][k];
	
	if(ret != -1){
		return ret;
	}
	
	ret = 0;
	
	for(int i = 0; i < 8; i++){
		ret += solve(dp, r + dr[i], c + dc[i], k - 1) / 8;
	}
	
	return ret;
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, x, y, k;
	cin >> n >> x >> y >> k;
	
	vector<vector<vector<double>>> dp(n + 1, vector<vector<double>>(n + 1, vector<double>(k + 1, -1)));
	
	cout << fixed;
	cout.precision(10);
	cout << solve(dp, x, y, k);
	
	return 0;
}