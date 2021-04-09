#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrix_sum(vector<vector<int>>& A, vector<vector<int>>& B){
	
	int n = A.size();
	
	vector<vector<int>> result(n, vector<int>(n));
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			result[i][j] = (A[i][j] + B[i][j]) % 1000;
		}
	}
	
	
	return result;
}

vector<vector<int>> matrix_multiplication(vector<vector<int>>& A, vector<vector<int>>& B){
	
	int n = A.size();
	
	vector<vector<int>> result(n, vector<int>(n));
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				result[i][j] += A[i][k] * B[k][j];
			}
			result[i][j] %= 1000;
		}
	}
	
	return result;
	
}

vector<vector<int>> pow(vector<vector<int>>& A, long long b){
	
	if(b == 1){
		return A;
	}
	
	vector<vector<int>> result = pow(A, b / 2);
	result = matrix_multiplication(result, result);
	
	if(b % 2 == 1){
		result = matrix_multiplication(result, A);
	}
	
	return result;
}

vector<vector<int>> pow_sum(vector<vector<int>>& A, long long b){
	
	if(b == 1){
		return A;
	}
	
	vector<vector<int>> A_pow_b = pow(A, b / 2);
	vector<vector<int>> sum = pow_sum(A, b / 2);
	vector<vector<int>> temp = matrix_multiplication(sum, A_pow_b);
	
	sum = matrix_sum(sum, temp);
	
	if(b % 2 == 1){
		temp = pow(A, b);
		sum = matrix_sum(sum, temp);
	}
	
	return sum;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	long long b;
	cin >> n >> b;
	
	vector<vector<int>> A(n, vector<int>(n));
	for(int i =0 ; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> A[i][j];
			A[i][j] %= 1000;
		}
	}
	
	A = pow_sum(A, b);
	
	for(int i =0 ; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << A[i][j] << " ";
		}
		cout << '\n';
	}
	
	return 0;
	
}