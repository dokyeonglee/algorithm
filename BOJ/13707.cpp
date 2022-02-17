#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	vector<vector<long long>> C(10005, vector<long long>(5005));
	C[1][0] = 1;
	C[1][1] = 1;
	
	for(int i = 2; i <= 10001; i++){
		C[i][0] = 1;
		for(int j = 1; j <= 5001; j++){
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % 1000000000;
		}
	}
	
	int n, k;
	cin >> n >> k;
	
	cout << C[n + k - 1][n];
	
	return 0;
}