#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> arr(n, vector<int>(m));
	for(int i = 0; i < n; i++){
		string str;
		cin >> str;
		for(int j = 0; j < m; j++){
			arr[i][j] = str[j] - '0';
		}
	}
	
	int answer = 0;
	
	for(int i = 0; i < (1 << (n * m)); i++){
		int result = 0;
		for(int r = 0; r < n; r++){
			int sum = 0;
			for(int c = 0; c < m; c++){
				if(i & (1 << (r * m + c))){
					sum = sum * 10 + arr[r][c];
				}else{
					result += sum;
					sum = 0;
				}
			}
			result += sum;
		}
		for(int c = 0; c < m; c++){
			int sum = 0;
			for(int r = 0; r < n; r++){
				if(i & (1 << (r * m + c))){
					result += sum;
					sum = 0;
				}else{
					sum = sum * 10 + arr[r][c];
				}
			}
			result += sum;
		}
		answer = max(answer, result);
	}
	
	cout << answer;
	
	return 0;
}