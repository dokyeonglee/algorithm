#include <iostream>
#include <vector>
using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<vector<int>> graph(26, vector<int>(26, 987654321));
	for(int i = 0; i < n; i++){
		string src, dst, _;
		cin >> src >> _ >> dst;
		graph[src[0] - 'a'][dst[0] - 'a'] = 1;
	}
	
	for(int k = 0; k < 26; k++){
		for(int i = 0; i < 26; i++){
			for(int j = 0; j < 26; j++){
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
	
	int m;
	cin >> m;
	
	for(int i = 0; i < m; i++){
		string src, dst, _;
		cin >> src >> _ >> dst;
		if(graph[src[0] - 'a'][dst[0] - 'a'] != 987654321){
			cout << "T\n";
		}else{
			cout << "F\n";
		}
	}
	
	return 0;
}