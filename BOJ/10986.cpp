#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<long long> arr(n + 1);
	vector<long long> cnt(m + 1);
	
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		arr[i] += arr[i - 1];
		arr[i] %= m;
		cnt[arr[i]]++;
	}
	
	long long answer = cnt[0];
	for(int i = 0; i < m; i++){
		answer += cnt[i] * (cnt[i] - 1) / 2;
	}
	
	cout << answer;
	
	return 0;
}