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
		
		int n;
		cin >> n;
		
		vector<long long> psum(n + 1);
		vector<long long> arr(n + 1);
		
		for(int i = 1; i <= n; i++){
			cin >> arr[i];
		}
		
		sort(arr.begin(), arr.end());
		
		for(int i = 1; i <= n; i++){
			psum[i] = psum[i - 1] + arr[i];
		}
		
		long long answer = 0;
		for(int i = 2; i <= n; i++){
			long long result = 1e18;
			for(int j = 1; j + i <= n + 1; j++){
				result = min(result, arr[j + i - 1] * i - (psum[j + i - 1] - psum[j - 1]));
			}
			answer += result;
		}
		
		cout << answer << "\n";
		
	}
	
	return 0;
}