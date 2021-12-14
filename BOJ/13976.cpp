#include <iostream>
#include <vector>

using namespace std;

const int mod = 1e9 + 7;

vector<vector<long long>> mat_mul(vector<vector<long long>>& a, vector<vector<long long>>& b){
	vector<vector<long long>> result(a.size(), vector<long long>(b[0].size()));
	for(int i = 0; i < a.size(); i++){
		for(int j = 0; j < b[0].size(); j++){
			for(int k = 0; k < a[0].size(); k++){
				result[i][j] += a[i][k] * b[k][j];
				result[i][j] = (result[i][j] + mod) % mod;
			}
		}
	}
	return result;
}

vector<vector<long long>> pow(vector<vector<long long>> a, long long n){
	if(n == 0){
		return {{1, 0}, {0, 1}};
	}
	vector<vector<long long>> result = pow(a, n / 2);
	result = mat_mul(result, result);
	if(n % 2 == 1){
		result = mat_mul(result, a);
	}
	return result;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n;
	cin >> n;
	
	if(n % 2 == 1){
		cout << 0;
	}else{
		vector<vector<long long>> answer = pow({{4, -1}, {1, 0}}, n / 2);
		cout << (answer[0][0] + answer[0][1]) % mod;
	}
	
	return 0;
}