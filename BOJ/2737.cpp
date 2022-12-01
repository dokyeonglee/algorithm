#include <iostream>
using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		long long n;
		cin >> n;
		int answer = 0;
		for(long long i = 2; i * (i + 1) / 2 <= n; i++){
			long long result = i * (i + 1) / 2;
			if((n - result) % i == 0){
				answer++;
			}
		}
		cout << answer << "\n";
	}
	
	return 0;
}