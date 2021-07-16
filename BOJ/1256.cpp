#include <iostream>
#include <vector>

using namespace std;

int number_of_words(vector<vector<int>>& dp, int n, int m){
	
	if(n == 0 or m == 0){
		return 1;
	}
	
	int& ret = dp[n][m];
	
	if(ret != -1){
		return ret;
	}
	
	ret = min(number_of_words(dp, n - 1, m) + number_of_words(dp, n, m - 1), 1000000001);
	
	return ret;
}

bool solve(vector<vector<int>>& dp, int n, int m, int k, int skip, string& word){
	
	if(n == 0){
		for(int i = 0; i < m; i++){
			word += 'z';
		}
		return true;
	}
	
	if(m == 0){
		for(int i = 0; i < n; i++){
			word += 'a';
		}
		return true;
	}
	
	int idx = number_of_words(dp, n - 1, m);
	
	if(skip < idx){
		word += 'a';
		solve(dp, n - 1, m, k, skip, word);
		return true;
	}else if(skip <= k){
		word += 'z';
		solve(dp, n, m - 1, k, skip - idx, word);
		return true;
	}else{
		return false;
	}
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
	
	if(number_of_words(dp, n, m) < k){
		cout << -1;
	}else{
		string answer = "";
		if(solve(dp, n, m, k, k - 1, answer)){
			cout << answer;
		}else{
			cout << -1;
		}
	}
	
	return 0;
}