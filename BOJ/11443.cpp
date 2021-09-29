#include <iostream>
#include <vector>

using namespace std;

const int mod = 1000000007;

vector<vector<long long>> fib_mul = {{1, 1}, {1, 0}};

vector<vector<long long>> mat_mul(vector<vector<long long>>& arr, vector<vector<long long>>& brr){
	
	vector<vector<long long>> result(arr.size(), vector<long long>(brr[0].size()));
	
	for(int i = 0; i < arr.size(); i++){
		for(int j = 0; j < brr[0].size(); j++){
			for(int k = 0; k < arr[0].size(); k++){
				result[i][j] += arr[i][k] * brr[k][j];
				result[i][j] %= mod;
			}
		}
	}
	
	return result;
	
}

vector<vector<long long>> fib(long long n){
	
	if(n <= 1){
		return fib_mul;
	}
	
	vector<vector<long long>> temp = fib(n / 2);
	temp = mat_mul(temp, temp);
	
	if(n % 2 == 1){
		temp = mat_mul(temp, fib_mul);
	}
	
	return temp;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n;
	cin >> n;
	
	n = n + 1 - n % 2;
	
	vector<vector<long long>> answer = fib(n);
	cout << answer[0][1] - 1;
	
	return 0;
}