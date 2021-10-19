#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<vector<int>> arr(n + 1, vector<int>(n + 1, 987654321));
	for(int i = 1; i <= n; i++){
		arr[i][i] = 0;
	}
	
	while(1){
		int u, v;
		cin >> u >> v;
		if(u == -1 and v == -1){
			break;
		}
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
	
	vector<int> answer;
	int min_score = n + 1;
	
	for(int i = 1; i <= n; i++){
		int score = 0;
		for(int j = 1; j <= n; j++){
			score = max(score, arr[i][j]);
		}
		if(score < min_score){
			min_score = score;
			answer.clear();
			answer.push_back(i);
		}else if(score == min_score){
			answer.push_back(i);
		}
	}
	
	cout << min_score << " " << answer.size() << "\n";
	for(int i = 0; i < answer.size(); i++){
		cout << answer[i] << " ";
	}
	
	return 0;
}