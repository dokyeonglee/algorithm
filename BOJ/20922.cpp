#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	vector<int> arr(n);
	vector<int> cnt(100001);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	int left = 0;
	int right = 0;
	int answer = 0;
	
	while(right < n){
		
		if(cnt[arr[right]] < k){
			cnt[arr[right++]]++;
			answer = max(answer, right - left);
		}else{
			cnt[arr[left++]]--;
		}
		
	}
	
	cout << answer;
	
	return 0;
}