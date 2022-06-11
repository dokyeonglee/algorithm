#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> arr(n, vector<int>(n));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> arr[i][j];
		}
	}
	
	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}
	
	for(int i = 0; i < m; i++){
		int u, v, t;
		cin >> u >> v >> t;
		if(arr[u - 1][v - 1] > t){
			cout << "Stay here\n";
		}else{
			cout << "Enjoy other party\n";
		}
	}
	
	return 0;
}