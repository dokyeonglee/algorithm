#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<long long>> arr(n + 1, vector<long long>(m + 1));
	for(int i = 1; i <= n; i++){
		string str;
		cin >> str;
		for(int j = 1; j <= m; j++){
			arr[i][j] = str[j - 1] - '0';
			arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
		}
	}

	long long answer = 0;
	
	for(int i = 1; i < m; i++){// ||
		for(int j = i + 1; j < m; j++){
			answer = max(answer, arr[n][i] * (arr[n][j] - arr[n][i]) * (arr[n][m] - arr[n][j]));
		}
	}
	
	for(int i = 1; i < n; i++){// =
		for(int j = i + 1; j < n; j++){
			answer = max(answer, arr[i][m] * (arr[j][m] - arr[i][m]) * (arr[n][m] - arr[j][m]));
		}
	}
	
	for(int i = 1; i < m; i++){// ㅏ
		for(int j = 1; j < n; j++){
			answer = max(answer, arr[n][i] * (arr[j][m] - arr[j][i]) * (arr[n][m] - arr[j][m] - arr[n][i] + arr[j][i]));
		}
	}
	
	for(int i = 1; i < m; i++){// ㅓ
		for(int j = 1; j < n; j++){
			answer = max(answer, (arr[n][m] - arr[n][i]) * arr[j][i] * (arr[n][i] - arr[j][i]));
		}
	}
	
	for(int i = 1; i < n; i++){// ㅜ
		for(int j = 1; j < m; j++){
			answer = max(answer, arr[i][m] * (arr[n][j] - arr[i][j]) * (arr[n][m] - arr[n][j] - arr[i][m] + arr[i][j]));
		}
	}
	
	for(int i = 1; i < n; i++){// ㅗ
		for(int j = 1; j < m; j++){
			answer = max(answer, arr[i][j] * (arr[i][m] - arr[i][j]) * (arr[n][m] - arr[i][m]));
		}
	}
	
	cout << answer;
	
	return 0;
}