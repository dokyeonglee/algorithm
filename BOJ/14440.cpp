#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<vector<int>> matmul(vector<vector<int>> arr, vector<vector<int>> brr){
	vector<vector<int>> result(2, vector<int>(2));
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			for(int k = 0; k < 2; k++){
				result[i][j] += arr[i][k] * brr[k][j];
				result[i][j] %= 100;
			}
		}
	}
	return result;
}

vector<vector<int>> pow(vector<vector<int>> arr, int n){
	if(n == 0){
		return {{1, 0}, {0, 1}};
	}
	vector<vector<int>> temp = pow(arr, n / 2);
	temp = matmul(temp, temp);
	if(n % 2 == 1){
		temp = matmul(temp, arr);
	}
	return temp;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int x, y, a0, a1, n;
	cin >> x >> y >> a0 >> a1 >> n;
	
	int answer;
	
	if(n == 0){
		answer = a0;
	}else if(n == 1){
		answer = a1;
	}else{
		vector<vector<int>> result = pow({{x, y}, {1, 0}}, n - 1);
		answer = (result[0][0] * a1 + result[0][1] * a0) % 100;
	}
	
	if(abs(answer) < 10){
		if(answer < 0){
			cout << "-0" << abs(answer);
		}else{
			cout << "0" << answer;
		}
	}else{
		cout << answer;
	}
	
	return 0;
}