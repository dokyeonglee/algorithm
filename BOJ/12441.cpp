#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	for(int t = 1; t <= T; t++){
		
		int n, p, m;
		cin >> n >> p >> m;
		
		vector<pair<int, int>> friends(p);
		for(int i = 0; i < p; i++){
			cin >> friends[i].first >> friends[i].second;
		}
		
		vector<vector<long long>> arr(n + 1, vector<long long>(n + 1, 987654321));
		
		for(int i = 0; i < m; i++){
			
			int d, l;
			cin >> d >> l;
			
			int u, v;
			cin >> u;
			
			for(int j = 1; j < l; j++){
				cin >> v;
				arr[u][v] = d;
				arr[v][u] = d;
				u = v;
			}
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
		
		long long answer = 987654321;
		
		for(int i = 1; i <= n; i++){
			long long result = 0;
			for(int j = 0; j < p; j++){
				result = max(result, arr[i][friends[j].first] * friends[j].second);
			}
			answer = min(answer, result);
		}
		
		if(answer >= 987654321){
			answer = -1;
		}
		
		cout << "Case #" << t << ": " << answer << "\n";
		
	}
	
	return 0;
}