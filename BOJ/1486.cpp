#include <iostream>
#include <vector>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, t, d;
	cin >> n >> m >> t >> d;
	
	vector<vector<int>> arr(n, vector<int>(m));
	vector<vector<int>> graph(n * m, vector<int>(n * m, 987654321));
	
	for(int i = 0; i < n; i++){
		string str;
		cin >> str;
		for(int j = 0; j < m; j++){
			if(str[j] >= 'a'){
				arr[i][j] = str[j] - 'a' + 26;
			}else{
				arr[i][j] = str[j] - 'A';
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int now = i * m + j;
			for(int k = 0; k < 4; k++){
				int next_r = i + dr[k];
				int next_c = j + dc[k];
				if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= m){
					continue;
				}
				int diff = abs(arr[i][j] - arr[next_r][next_c]);
				if(diff <= t){
					if(arr[i][j] < arr[next_r][next_c]){
						graph[now][next_r * m + next_c] = diff * diff;
					}else{
						graph[now][next_r * m + next_c] = 1;
					}
				}
			}
		}
	}
	
	for(int k = 0; k < n * m; k++){
		for(int i = 0; i < n * m; i++){
			for(int j = 0; j < n * m; j++){
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}	
		}
	}
	
	int answer = arr[0][0];
	for(int i = 1; i < n * m; i++){
		if(graph[0][i] + graph[i][0] <= d){
			answer = max(answer, arr[i / m][i % m]);
		}
	}
	
	cout << answer;
	
	return 0;
}