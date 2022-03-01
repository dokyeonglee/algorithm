#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> arr(n + 2, vector<int>(m + 2));
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> arr[i][j];
		}
	}
	
	int min_count = 987654321;
	vector<vector<int>> answer(n + 2, vector<int>(m + 2));

	for(int i = 0; i < (1 << m); i++){
		vector<vector<int>> temp(arr);
		vector<vector<int>> result(n + 2, vector<int>(m + 2));
		int cnt = 0;
		for(int j = 0; j < m; j++){
			if(i & (1 << j)){
				cnt++;
				temp[0][j + 1] ^= 1;
				temp[1][j] ^= 1;
				temp[1][j + 1] ^= 1;
				temp[2][j + 1] ^= 1;
				temp[1][j + 2] ^= 1;
				result[1][j + 1] = 1;
			}
		}
	
		for(int r = 2; r <= n; r++){
			for(int c = 1; c <= m; c++){
				if(temp[r - 1][c] == 1){
					cnt++;
					temp[r - 1][c] ^= 1;
					temp[r][c - 1] ^= 1;
					temp[r][c] ^= 1;
					temp[r + 1][c] ^= 1;
					temp[r][c + 1] ^= 1;
					result[r][c] = 1;
				}
			}
		}
		
		bool check = true;
		
		for(int r = 1; r <= n; r++){
			for(int c = 1; c <= m; c++){
				if(temp[r][c] == 1){
					check = false;
				}
			}
		}
		
		if(check){
			if(cnt < min_count){
				min_count = cnt;
				answer = result;
			}else if(cnt == min_count){
				answer = min(answer, result);
			}
		}
		
	}
	
	if(min_count == 987654321){
		cout << "IMPOSSIBLE";
	}else{
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cout << answer[i][j] << " ";
			}
			cout << "\n";
		}
	}
	
	return 0;
}