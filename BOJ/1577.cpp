#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m;
	cin >> n >> m;
		
	int k;
	cin >> k;
	
	set<pair<pair<int, int>, pair<int, int>>> cant_go;
	
	for(int i = 0; i < k; i++){
		int a, b, c, d;
		cin >> b >> a >> d >> c;
		cant_go.insert(make_pair(make_pair(a, b), make_pair(c, d)));
		cant_go.insert(make_pair(make_pair(c, d), make_pair(a, b)));
	}
	
	vector<vector<long long>> dp(m + 1, vector<long long>(n + 1));
    
    dp[0][0] = 1;
	for(int i = 1; i <= m; i++){
		if(cant_go.find(make_pair(make_pair(i - 1, 0), make_pair(i, 0))) == cant_go.end()){
            dp[i][0] = dp[i - 1][0];
        }
	}
	for(int i = 1; i <= n; i++){
		if(cant_go.find(make_pair(make_pair(0, i - 1), make_pair(0, i))) == cant_go.end()){
            dp[0][i] = dp[0][i - 1];
		}
	}
	
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			if(cant_go.find(make_pair(make_pair(i - 1, j), make_pair(i, j))) == cant_go.end()){
				dp[i][j] += dp[i - 1][j];
			}
			if(cant_go.find(make_pair(make_pair(i, j - 1), make_pair(i, j))) == cant_go.end()){
				dp[i][j] += dp[i][j - 1];
			}
		}
	}
	
	cout << dp[m][n];
	
	return 0;
}