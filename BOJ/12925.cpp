#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
 
vector<vector<int>> matmul(vector<vector<int>> arr, vector<vector<int>> brr){
 
	vector<vector<int>> result(arr.size(), vector<int>(brr[0].size()));
 
	for(int i = 0; i < arr.size(); i++){
		for(int j = 0; j < brr[0].size(); j++){
			for(int k = 0; k < brr.size(); k++){
				result[i][j] += arr[i][k] * brr[k][j];
				result[i][j] %= 1000;
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
	cout.fill('0');
 
	int T;
	cin >> T;
 
	for(int test_case = 1; test_case <= T; test_case++){
		int n;
		cin >> n;
		vector<vector<int>> result = pow({{6, -4}, {1, 0}}, n);
		cout << "Case #" << test_case << ": ";
		cout << setw(3) << ((6 * result[1][0] + 2 * result[1][1] + 999) % 1000 + 1000) % 1000 << "\n";
	}
 
	return 0;
}