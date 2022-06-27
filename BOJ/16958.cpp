#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, t;
	cin >> n >> t;
	
	vector<int> teleportable(n);
	vector<pair<int, int>> arr(n);
	bool check = 0;
	for(int i = 0; i < n; i++){
		cin >> teleportable[i] >> arr[i].first >> arr[i].second;
	}
	
	vector<vector<int>> dist(n, vector<int>(n));
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			dist[i][j] = abs(arr[i].first - arr[j].first) + abs(arr[i].second - arr[j].second);
			if(teleportable[i] and teleportable[j]){
				dist[i][j] = min(dist[i][j], t);
			}
			dist[j][i] = dist[i][j];
		}
	}
	
	int m;
	cin >> m;
	
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		int direct = dist[u - 1][v - 1];
		int u_to_teleport = 987654321;
		for(int i = 0; i < n; i++){
			if(teleportable[i]){
				u_to_teleport = min(u_to_teleport, dist[u - 1][i]);
			}
		}
		int v_to_teleport = 987654321;
		for(int i = 0; i < n; i++){
			if(teleportable[i]){
				v_to_teleport = min(v_to_teleport, dist[v - 1][i]);
			}
		}
		cout << min(direct, u_to_teleport + t + v_to_teleport) << "\n";
	}
	
	return 0;
}