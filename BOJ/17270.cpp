#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int v, m;
	cin >> v >> m;
	
	vector<vector<long long>> arr(v + 1, vector<long long>(v + 1, 1e17));
	
	for(int i = 1; i <= v; i++){
		arr[i][i] = 0;
	}
	
	for(int i = 0; i < m; i++){
		long long u, v, c;
		cin >> u >> v >> c;
		arr[u][v] = min(arr[u][v], c);
		arr[v][u] = arr[u][v];
	}
	
	int a, b;
	cin >> a >> b;
	
	for(int k = 1; k <= v; k++){
		for(int i = 1; i <= v; i++){
			for(int j = 1; j <= v; j++){
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}	
	}
	
	vector<int> answer_v;
	long long min_dist = 1e17;

	for(int i = 1; i <= v; i++){
		if(i != a and i != b and arr[a][i] != 1e17 and arr[b][i] != 1e17){
			long long sum = arr[a][i] + arr[b][i];
			if(min_dist > sum){
				min_dist = sum;
				answer_v.clear();
				answer_v.push_back(i);
			}else if(min_dist == sum){
				answer_v.push_back(i);
			}
		}
	}
	
	long long min_a_dist = 1987654321;
	int answer = -1;
	
	for(int i = 0; i < answer_v.size(); i++){
		if(arr[a][answer_v[i]] <= arr[b][answer_v[i]]){
			if(min_a_dist > arr[a][answer_v[i]]){
				min_a_dist = arr[a][answer_v[i]];
				answer = answer_v[i];
			}
		}
	}
	
	cout << answer;
	
	return 0;
}