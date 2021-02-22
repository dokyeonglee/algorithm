#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<string> board(n);
	for(int i = 0; i < n; i++){
		cin >> board[i];
	}
	
	int answer = 1;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			for(int k = min(n, m) - 1; k > 0; k--){
				if(i + k < n and j + k < m){
					if(board[i][j] == board[i + k][j] and board[i][j] == board[i][j + k] and board[i][j] == board[i + k][j + k]){
						answer = max(answer, k + 1);
						break;
					}
				}
			}
		}
	}
	
	answer *= answer;
	cout << answer;
	
	return 0;
}