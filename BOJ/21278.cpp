#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> arr(n + 1, vector<int>(n + 1, 9876543));
	
	for(int i = 1; i <= n; i++){
		arr[i][i] = 0;
	}
	
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		arr[u][v] = 1;
		arr[v][u] = 1;
	}
	
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}
	
	int u, v, answer = 9876543;
	
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			
			int result = 0;
			
			for(int k = 1; k <= n; k++){
				result += min(arr[i][k], arr[j][k]);
			}
			
			if(answer > result){
				answer = result;
				u = i;
				v = j;
			}
			
		}
	}
	
	cout << u << " " << v << " " << answer * 2;
	
	return 0;
}