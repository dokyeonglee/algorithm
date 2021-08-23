#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> beads(n + 1, vector<int>(n + 1));
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		beads[u][v] = 1;
		beads[v][u] = -1;
	}
	
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(beads[i][k] == 1 and beads[k][j] == 1){
					beads[i][j] = 1;	
				}
				if(beads[i][k] == -1 and beads[k][j] == -1){
					beads[i][j] = -1;
				}
			}
		}
	}
	
	int answer = 0;
	
	for(int i = 1; i <= n; i++){
		
		int cnt = 0;
		int cnt2 = 0;
		
		for(int j = 1; j <= n; j++){
			
			if(beads[i][j] == 1){
				cnt++;
			}
			if(beads[i][j] == -1){
				cnt2++;
			}
		}
		
		if(cnt > n / 2 or cnt2 > n / 2){
			answer++;
		}
		
	}
	
	cout << answer;
	
	return 0;
}