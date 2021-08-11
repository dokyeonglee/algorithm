#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	vector<int> psum(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> psum[i];
		psum[i] += psum[i - 1];
	}
	
	long long answer = 0;
	map<int, long long> cnt;
	for(int i = 1; i <= n; i++){
		if(psum[i] == k){
			answer++;		
		}
		answer += cnt[psum[i] - k];
		cnt[psum[i]]++;
	}
	
	cout << answer;
	
	return 0;
}