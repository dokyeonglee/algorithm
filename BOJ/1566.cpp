#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> arr(n, vector<int>(m));
	vector<int> row_sum(n);
	vector<int> col_sum(m);
	
	for(int i = 0; i < n; i++){
		int sum = 0;
		for(int j = 0; j < m; j++){
			cin >> arr[i][j];
			row_sum[i] += arr[i][j];
			col_sum[j] += arr[i][j];
		}
	}
	
	int answer = 987654321;
	
	for(int i = 0; i < (1 << n); i++){
		vector<int> temp_row_sum(row_sum);
		vector<int> temp_col_sum(col_sum);
		for(int j = 0; j < n; j++){
			if(i & (1 << j)){
				temp_row_sum[j] = -temp_row_sum[j];
				for(int k = 0; k < m; k++){
					temp_col_sum[k] -= 2 * arr[j][k];
				}
			}
		}
		
		int cnt = 0;
		bool check = true;
		
		for(int j = 0; j < m; j++){
			if(temp_col_sum[j] < 0){
				cnt++;
				for(int k = 0; k < n; k++){
					if(i & (1 << k)){
						temp_row_sum[k] += 2 * arr[k][j];
					}else{
						temp_row_sum[k] -= 2 * arr[k][j];
					}
				}
			}
			if(temp_col_sum[j] == 0){
				check = false;
				break;
			}
		}
		
		if(check){
			for(int j = 0; j < n; j++){
				if(temp_row_sum[j] <= 0){
					check = false;
					break;
				}
			}
		}
		
		if(check){
			answer = min(answer, __builtin_popcount(i) + cnt);
		}
	}
	
	if(answer == 987654321){
		answer = -1;
	}
	
	cout << answer;
	
	return 0;
}