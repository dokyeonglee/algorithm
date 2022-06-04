#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	while(T--){
		
		int k, n;
		cin >> k >> n;
		
		vector<vector<int>> arr(4, vector<int>(n));
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < n; j++){
				cin >> arr[i][j];
			}
		}
		
		vector<int> sum(n * n);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				sum[i * n + j] = arr[0][i] + arr[1][j];
			}
		}
		
		sort(sum.begin(), sum.end());
		int answer = 987654321;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				int idx = lower_bound(sum.begin(), sum.end(), k - arr[2][i] - arr[3][j]) - sum.begin();
				if(idx == sum.size()){
					--idx;
				}
				int temp = arr[2][i] + arr[3][j] + sum[idx];
				if(abs(answer - k) == abs(temp - k)){
					answer = min(answer, temp);
				}else if(abs(answer - k) > abs(temp - k)){
					answer = temp;
				}
				if(idx > 0){
					temp = arr[2][i] + arr[3][j] + sum[idx - 1];
					if(abs(answer - k) == abs(temp - k)){
						answer = min(answer, temp);
					}else if(abs(answer - k) > abs(temp - k)){
						answer = temp;
					}
				}
			}
		}
		cout << answer << "\n";
	}
	
	return 0;
}