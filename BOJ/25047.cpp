#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<vector<long long>> arr(n, vector<long long>(n));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> arr[i][j];
		}
	}
	
	long long answer = -1e18;
	for(int i = 0; i < (1 << n); i++){
		long long result = 0;
		for(int c = 0; c < n; c++){
			long long score1 = 0;
			long long score2 = 0;
			for(int r = 0; r < n; r++){
				if(i & (1 << r)){
					score1 += arr[r][c];
				}else{
					score2 += arr[r][c];
				}
			}
			result += min(score1, score2);
		}
		answer = max(answer, result);
	}
	
	cout << answer;
	
	return 0;
}