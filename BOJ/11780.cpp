#include <iostream>
#include <vector>

using namespace std;

void find_path(vector<vector<int>>& before, vector<int>& path, int from, int to){
	int prev = before[from][to];
	if(from == prev){
		path.push_back(from);
		return;
	}
	find_path(before, path, from, prev);
	find_path(before, path, prev, to);
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<vector<int>> arr(n + 1, vector<int>(n + 1, 987654321));
	vector<vector<int>> before(n + 1, vector<int>(n + 1, -1));
	
	int m;
	cin >> m;
	
	for(int i = 0; i < m; i++){
		int u, v, c;
		cin >> u >> v >> c;
		arr[u][v] = min(arr[u][v], c);
		before[u][v] = u;
	}
	
	for(int i = 1; i <= n; i++){
		arr[i][i] = 0;
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			before[i][j] = i;
		}
	}
	
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(arr[i][j] > arr[i][k] + arr[k][j]){
					arr[i][j] = arr[i][k] + arr[k][j];
					before[i][j] = k;
				}
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(arr[i][j] == 987654321){
				arr[i][j] = 0;
			}
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			vector<int> path;
			if(arr[i][j] != 0){
				find_path(before, path, i, j);
				path.push_back(j);
			}
			cout << path.size() << " ";
			for(int k = 0; k < path.size(); k++){
				cout << path[k] << " ";
			}
			cout << "\n";
		}
	}
	
	return 0;
}