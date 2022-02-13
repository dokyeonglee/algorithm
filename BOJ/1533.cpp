#include <iostream>
#include <vector>

using namespace std;

const int mod = 1e6 + 3;

vector<vector<long long>> mat_mul(vector<vector<long long>>& a, vector<vector<long long>>& b){
	vector<vector<long long>> result(a.size(), vector<long long>(b[0].size()));
	for(int i = 0; i < a.size(); i++){
		for(int j = 0; j < b[0].size(); j++){
			for(int k = 0; k < b.size(); k++){
				result[i][j] += a[i][k] * b[k][j];
				result[i][j] %= mod;
			}
		}
	}
	return result;
}

vector<vector<long long>> pow(vector<vector<long long>>& arr, int n){
	if(n == 1){
		return arr;
	}
	auto result = pow(arr, n / 2);
	result = mat_mul(result, result);
	if(n % 2 == 1){
		result = mat_mul(result, arr);
	}
	return result;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, s, e, t;
	cin >> n >> s >> e >> t;
	
	vector<vector<long long>> graph(5 * n + 4, vector<long long>(5 * n + 4));
	
	for(int i = 0; i < n; i++){
		
		string str;
		cin >> str;
		
		for(int j = 0; j < 3; j++){
			graph[n + 4 * i + j][n + 4 * i + j + 1] = 1;
		}
		
		for(int j = 0; j < n; j++){
			int c = str[j] - '0';
			if(c > 1){
				graph[i][n + 4 * i] = 1;
				graph[n + 4 * i + c - 2][j] = 1;
			}else if(c == 1){
				graph[i][j] = 1;
			}
		}
	}
	
	auto answer = pow(graph, t);
	cout << answer[s - 1][e - 1];
	
	return 0;
}