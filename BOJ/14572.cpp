#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k, d;
	cin >> n >> k >> d;
	
	vector<pair<long long, long long>> arr(n);
	for(int i = 0; i < n; i++){
		int x;
		cin >> x >> arr[i].first;
		for(int j = 0; j < x; j++){
			int a;
			cin >> a;
			arr[i].second |= (1ll << a);
		}
	}
	
	sort(arr.begin(), arr.end());
	
	vector<int> cnt(k + 1);
	
	long long answer = 0;
	int left = 0;
	int right = 0;
	
	while(right < n){
		if(arr[right].first - arr[left].first <= d){
			long long total = 0;
			long long common = 0;
			for(int i = 0; i <= k; i++){
				if(arr[right].second & (1ll << i)){
					cnt[i]++;
				}
			}
			for(int i = 0; i <= k; i++){
				if(cnt[i] != 0 and cnt[i] == right - left + 1){
					common++;
				}
				if(cnt[i] > 0){
					total++;
				}
			}
			
			answer = max(answer, (total - common) * (right - left + 1));
			right++;
		}else{
			for(int i = 0; i <= k; i++){
				if(arr[left].second & (1ll << i)){
				cnt[i]--;
				}
			}
			left++;
		}
	}
	
	cout << answer;
	
	return 0;
}