#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	vector<long long> cnt(1e6 + 5);
	for(int i = 0; i < n; i++){
		int s, e;
		cin >> s >> e;
		cnt[s + 1]++;
		cnt[e + 1]--;
	}
	
	for(int i = 1; i <= 1e6; i++){
		cnt[i] += cnt[i - 1];
	}
	
	int left = 0;
	int right = 0;
	long long sum = 0;
	
	while(left <= right and right <= 1e6){
		if(sum < k){
			sum += cnt[++right];
		}else if(sum > k){
			sum -= cnt[++left];
		}else{
			cout << left << " " << right;
			return 0;
		}
	}
	
	cout << "0 0";
	
	return 0;
}