#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int mod = 1e9 + 7;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	while(T--){
		
		int n;
		cin >> n;
		
		vector<int> arr(n);
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		
		vector<int> cnt(n);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(arr[j] % arr[i] == 0){
					cnt[j]++;
				}
			}
		}
		
		vector<int> prime;
		for(int i = 0; i < n; i++){
			if(cnt[i] == 2){
				prime.push_back(arr[i]);
			}
		}
		
		sort(prime.begin(), prime.end());
		
		long long answer = 1;
		for(int i = 0; i < n; i++){
			for(int p : prime){
				if(p > arr[i]){
					break;
				}
				long long result = 1;
				while(arr[i] % p == 0){
					result *= p;
					arr[i] /= p;
				}
				result = result / p * (p - 1);
				if(result > 0){
					answer = answer * result % mod;
				}
			}
		}
		cout << answer << "\n";
	}
	
	return 0;
}