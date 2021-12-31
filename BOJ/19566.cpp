#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n, k;
	cin >> n >> k;
	
	vector<long long> arr(n + 1);
	map<long long, long long> cnt;
	
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		arr[i] += arr[i - 1] - k;
		cnt[arr[i]]++;
	}

	long long answer = 0;
	
	for(auto c : cnt){
		if(c.first == 0){
			answer += cnt[0] * (cnt[0] + 1) / 2;
		}else if(c.second){
			answer += c.second * (c.second - 1) / 2;
		}
	}
	
	cout << answer;
	
	return 0;
}