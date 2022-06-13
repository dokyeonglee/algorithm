#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	while(1){
		int n, k, s;
		cin >> n >> k >> s;
		if(n == 0){
			break;
		}
		int answer = 0;
		for(int i = 0; i < (1 << n); i++){
			int sum = 0;
			if(__builtin_popcount(i) == k){
				for(int j = 0; j < n; j++){
					if(i & (1 << j)){
						sum += j + 1;
					}
				}
			}
			if(sum == s){
				answer++;
			}
		}
		cout << answer << "\n";
	}

	return 0;
}