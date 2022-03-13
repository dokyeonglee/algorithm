#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> mat_mul(vector<vector<long long>>& arr, vector<vector<long long>>& brr){
	vector<vector<long long>> result(arr.size(), vector<long long>(brr[0].size()));
	for(int i = 0; i < arr.size(); i++){
		for(int j = 0; j < brr[0].size(); j++){
			for(int k = 0; k < arr[0].size(); k++){
				result[i][j] += arr[i][k] * brr[k][j];
				result[i][j] %= 1000000007;
			}
		}
	}
	return result;
}

vector<vector<long long>> pow(vector<vector<long long>>& arr, long long n){
	vector<vector<long long>> result(arr.size(), vector<long long>(arr[0].size()));
	for(int i = 0; i < result.size(); i++){
		result[i][i] = 1;
	}
	while(n > 0){
		if(n % 2 == 1){
			result = mat_mul(result, arr);
		}
		arr = mat_mul(arr, arr);
		n >>= 1;
	}
	return result;
}

int main() {
	
	long long k, n;
	cin >> k >> n;
	
	vector<vector<long long>> arr(k + 2, vector<long long>(k + 2));
	for(int i = 0; i < k + 2; i++){
		for(int j = 0; j <= i; j++){
			arr[i][j] = 1;
		}
	}
	
	auto result = pow(arr, n - 1)[k + 1];
	long long answer = 0;
	
	for(int i = 0; i < result.size(); i++){
		answer += result[i];
		answer %= 1000000007;
	}
	
	cout << answer;
	
	return 0;
}