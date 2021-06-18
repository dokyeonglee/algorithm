#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n, k, q;
	cin >> n >> k >> q;
		
	while(q--){
		
		long long x, y;
		cin >> x >> y;
		
		if(k == 1){
			cout << abs(x - y) << "\n";
			continue;
		}
		
		long long answer = 0;
		
		while(x != y){
			long long temp = max(x, y);
			y = min(x, y);
			x = (temp - 2) / k + 1;
			answer++;
		}
		
		cout << answer << "\n";
		
	}
	
	return 0;
}