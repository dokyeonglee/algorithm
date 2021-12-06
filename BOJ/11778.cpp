#include <iostream>
#include <vector>

using namespace std;

const long long mod = 1e9 + 7;

long long gcd(long long a, long long b){
	return b ? gcd(b, a % b) : a;
}

vector<vector<long long>> mat_mul(vector<vector<long long>>& a, vector<vector<long long>>& b){
	vector<vector<long long>> result(a.size(), vector<long long>(b[0].size()));	
	for(int i = 0; i < a.size(); i++){
		for(int j = 0; j < b[0].size(); j++){
			for(int k = 0; k < a[0].size(); k++){
				result[i][j] += a[i][k] * b[k][j];
				result[i][j] %= mod;
			}
		}
	}
	return result;
}

vector<vector<long long>> pow(vector<vector<long long>>& arr, long long n){
	
	if(n == 0){
		return {{1, 0}, {0, 1}};
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
	
	long long n, m;
	cin >> n >> m;
	
	vector<vector<long long>> arr = {{1, 1}, {1, 0}};
	cout << pow(arr, gcd(n, m))[0][1];
	
	return 0;
}