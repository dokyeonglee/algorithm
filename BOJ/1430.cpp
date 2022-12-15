#include <iostream>
#include <queue>

using namespace std;

bool reachable(pair<int, int>& a, pair<int, int>& b, int r){
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second) <= r * r;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, r, d, x, y;
	cin >> n >> r >> d >> x >> y;
	
	vector<pair<int, int>> arr(n + 1);
	
	arr[0] = make_pair(x, y);
	for(int i = 1; i <= n; i++){
		cin >> arr[i].first >> arr[i].second;
	}
	
	vector<vector<int>> graph(n + 1, vector<int>(n + 1, 987654321));
	
	for(int i = 0; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			if(reachable(arr[i], arr[j], r)){
				graph[i][j] = 1;
				graph[j][i] = 1;
			}
		}
	}
	
	for(int k = 0; k <= n; k++){
		for(int i = 0; i <= n; i++){
			for(int j = 0; j <= n; j++){
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
	
	double answer = 0.0;
	
	for(int i = 1; i <= n; i++){
		if(graph[i][0] != 987654321){
			answer += (double)d / (1ll << (graph[i][0] - 1));
		}
	}
	
	cout << answer;
	
	return 0;
}