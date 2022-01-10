#include <iostream>
#include <vector>

using namespace std;

long long visited;

int solve(vector<vector<int>>& dp, vector<int>& STR, vector<int>& INT, vector<int>& PNT, int s, int i){
	
	int& ret = dp[s][i];
	if(ret != -1){
		return ret;
	}
	
	ret = 0;
	int pnt = 0;
	long long q = 0;
	
	for(int x = 0; x < STR.size(); x++){
		if(STR[x] <= s or INT[x] <= i){
			ret++;
			if(!(visited & (1 << x))){
				visited |= (1 << x);
				pnt += PNT[x];
				q |= (1 << x);
			}
		}
	}
	
	for(int p = 0; p <= pnt; p++){
		ret = max(ret, solve(dp, STR, INT, PNT, min(s + p, 1000), min(i + pnt - p, 1000)));
	}
	
	visited &= ~q;
	
	return ret;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> STR(n);
	vector<int> INT(n);
	vector<int> PNT(n);
	
	for(int i = 0; i < n; i++){
		cin >> STR[i] >> INT[i] >> PNT[i];
	}
	
	vector<vector<int>> dp(1001, vector<int>(1001, -1));
	cout << solve(dp, STR, INT, PNT, 1, 1);
	
	return 0;
}