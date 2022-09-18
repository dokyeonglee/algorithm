#include <iostream>
#include <vector>

using namespace std;

long long solve(vector<vector<long long>>& dp, int n, int m){
	
	if(n % m == 0){
		return n / m;
	}
	
	if(m % n == 0){
		return m / n;
	}
	
	long long& ret = dp[n][m];
	
	if(ret != -1){
		return dp[n][m];
	}
	
	ret = n * m;

    if(n >= 3 * m){
        ret = min(ret, solve(dp, n - m, m) + 1);
    }else{
        for(int i = 1; i <= n / 2; i++){
            ret = min(ret, solve(dp, i, m) + solve(dp, n - i, m));
        }
        
        for(int i = 1; i <= m / 2; i++){
            ret = min(ret, solve(dp, n, i) + solve(dp, n, m - i));
        }
    }
	
	return ret;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, -1));
	
	cout << solve(dp, n, m);
	
	return 0;
}