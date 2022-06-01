#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	int k;
	cin >> k;
	
	map<long long, long long> cnt;
	for(int i = 0; i < (1 << (n / 2)); i++){
		long long sum = 0;
		for(int j = 0; j < n / 2; j++){
			if(i & (1 << j)){
				sum += arr[j];
			}
		}
		cnt[sum] = i;
	}
	
	long long answer = 0;
	for(long long i = (1 << (n / 2)); i < (1ll << n); i += 1ll << (n / 2)){
		long long sum = 0;
		for(int j = n / 2; j < n; j++){
			if(i & (1ll << j)){
				sum += arr[j];
			}
		}
		if(cnt.count(k - sum)){
			answer = i | cnt[k - sum];
			break;
		}
	}
	
	for(int i = 0; i < n; i++){
		cout << ((answer & (1ll << i)) >> i);
	}
	
	return 0;
}