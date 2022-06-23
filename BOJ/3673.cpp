#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int c;
	cin >> c;
	
	while(c--){
		int n, d;
		cin >> d >> n;
		vector<long long> cnt(d);
		int sum = 0;
		long long answer = 0;
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			sum = (sum + x) % d;
			answer += cnt[sum]++;
		}
		answer += cnt[0];
		cout << answer << "\n";
	}
	
	return 0;
}