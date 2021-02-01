#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int dp[61][61][61];

int solve(int scv[3]){
	
	if(scv[0] <= 0 and scv[1] <= 0 and scv[2] <= 0){
		return 0;
	}
	
	int& res = dp[scv[0]][scv[1]][scv[2]];
	
	if(res != -1){
		return res;
	}
	
	int attack[] = {1, 3, 9};
	
	int ans = 987654321;
	
	do{
		int temp[3];
		for(int i = 0; i < 3; i++){
			temp[i] = max(scv[i] - attack[i], 0);
		}
		ans = min(ans, solve(temp) + 1);
	}while(next_permutation(attack, attack + 3));
	
	return res = ans;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	int scv[3] = {0};
	
	for(int i = 0; i < n; i++){
		cin >> scv[i];
	}
	
	memset(dp, -1, sizeof(dp));
	
	cout << solve(scv);
	
	return 0;
}