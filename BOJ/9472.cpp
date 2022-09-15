#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vector<long long> d(18);
	d[2] = 1;
	
	for(int i = 3; i <= 17; i++){
		d[i] = (i - 1) * (d[i - 1] + d[i - 2]);
	}
	
	vector<vector<long long>> c(18, vector<long long>(18));
	for(int i = 0; i <= 17; i++){
		for(int j = 0; j <= i; j++){
			if(j == 0 or i == j){
				c[i][j] = 1;
			}else{
				c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
			}
		}
	}
	
	int t;
	cin >> t;
	
	for(int test_case = 1; test_case <= t; test_case++){
		int a, n, k;
		cin >> a >> n >> k;
		long long answer = d[n];
		for(int i = k; i < n; i++){
			for(int j = 0; j <= n - i - 1; j++)
				answer += d[i + j] * c[n - i - 1][j];
		}
		cout << a << " " << answer + (k == 0) << "\n";
	}
	
	return 0;
}