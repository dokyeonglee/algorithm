#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	vector<long long> cnt(k + 5);
	vector<long long> cnt2(k + 5);
	for(int i = 0; i < n; i++){
		int s, e;
		cin >> s >> e;
		cnt[s]++;
		cnt[e + 1]--;
		cnt2[e + 1] -= e - s + 1;
	}
	
	for(int i = 1; i <= k; i++){
		cnt[i] += cnt[i - 1];
	}
	
	for(int i = 1; i <= k; i++){
		cnt[i] += cnt[i - 1] + cnt2[i];
		cout << cnt[i] << " ";
	}
	
	return 0;
}