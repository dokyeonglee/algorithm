#include <iostream>
#include <vector>

using namespace std;

int solve(vector<vector<vector<int>>>& dp, vector<int>& white, vector<int>& black, int idx, int white_cnt, int black_cnt){
	if(idx == dp.size() or (white_cnt == 15 and black_cnt == 15)){
		return 0;
	}
	int& ret = dp[idx][white_cnt][black_cnt];
	if(ret != -1){
		return ret;
	}
	ret = solve(dp, white, black, idx + 1, white_cnt, black_cnt);
	if(white_cnt < 15){
		ret = max(ret, solve(dp, white, black, idx + 1, white_cnt + 1, black_cnt) + white[idx]);
	}
	if(black_cnt < 15){
		ret = max(ret, solve(dp, white, black, idx + 1, white_cnt, black_cnt + 1) + black[idx]);
	}
	return ret;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vector<int> white;
	vector<int> black;
	
	int w, b;
	while(cin >> w >> b){
		white.push_back(w);
		black.push_back(b);
	}
	
	vector<vector<vector<int>>> dp(white.size(), vector<vector<int>>(16, vector<int>(16, -1)));
	cout << solve(dp, white, black, 0, 0, 0);
	return 0;
}