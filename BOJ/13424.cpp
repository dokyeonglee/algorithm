#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	while(T--){
		
		int n, m;
		cin >> n >> m;
		
		vector<vector<int>> arr(n + 1, vector<int>(n + 1, 98765432));
		for(int i = 0; i < m; i++){
			int u, v, c;
			cin >> u >> v >> c;
			arr[u][v] = c;
			arr[v][u] = c;
		}
		
		for(int i = 1; i <= n; i++){
			arr[i][i] = 0;
		}
		
		for(int k = 1; k <= n; k++){
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= n; j++){
					arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
				}
			}
		}
		
		int k;
		cin >> k;
		
		vector<int> friends(k);
		for(int i = 0; i < k; i++){
			cin >> friends[i];
		}
		
		int min_dist = 98765432;
		int answer = 0;
		
		for(int i = 1; i <= n; i++){
			int dist = 0;
			for(int j = 0; j < friends.size(); j++){
				dist += arr[friends[j]][i];
			}
			if(dist < min_dist){
				min_dist = dist;
				answer = i;
			}
		}	
		
		cout << answer << "\n";
	}
	
	return 0;
}