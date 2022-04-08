#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<vector<int>> graph(128, vector<int>(128, 987654321));
	
	for(int i = 0;i < n; i++){
		string _;
		char src, dst;
		cin >> src >> _ >> dst;
		graph[src][dst] = 1;
	}
	
	for(int k = 0; k < 128; k++){
		for(int i = 0; i < 128; i++){
			for(int j = 0; j < 128; j++){
				if(graph[i][j] > graph[i][k] + graph[k][j]){
					graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
				}
			}
		}
	}
	
	int cnt = 0;
	for(int i = 0; i < 128; i++){
		for(int j = 0; j < 128; j++){
			if(i != j and graph[i][j] != 987654321){
				cnt++;
			}
		}
	}
	
	cout << cnt << "\n";
	
	for(int i = 0; i < 128; i++){
		for(int j = 0; j < 128; j++){
			if(i != j and graph[i][j] != 987654321){
				cout << (char)i << " => " << (char)j << "\n";
			}
		}
	}
	
	return 0;
}