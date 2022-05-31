#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<vector<int>> arr(n, vector<int>(n));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> arr[i][j];
		}
	}
	
	int answer = n * n;
	for(int i = 0; i < (1 << n); i++){
		for(int j = 0; j < (1 << n); j++){
			vector<vector<int>> temp(arr);
			for(int r = 0; r < n; r++){
				if(i & (1 << r)){
					for(int c = 0; c < n; c++){
						temp[r][c] ^= 1;
					}
				}
			}
			for(int c = 0; c < n; c++){
				if(j & (1 << c)){
					for(int r = 0; r < n; r++){
						temp[r][c] ^= 1;
					}
				}
			}
			
			int one_cnt = 0;
			int zero_cnt = 0;
		
			for(int r = 0; r < n; r++){
				for(int c = 0; c < n; c++){
					one_cnt += temp[r][c];
					zero_cnt += temp[r][c] ^ 1;
				}
			}
		
			answer = min(answer, __builtin_popcount(i) + __builtin_popcount(j) + min(one_cnt, zero_cnt));
		}
		
	}
	
	cout << answer;
	
	return 0;
}