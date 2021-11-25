#include <iostream>
#include <vector>

using namespace std;

long long gcd(long long a, long long b){
	return b ? gcd(b, a % b) : a;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	for(int test_case = 1; test_case <= T; test_case++){
		
		long long a, b, n;
		cin >> a >> b >> n;
		
		vector<int> factor;
		long long temp = n;
		
		for(long long i = 2; i * i <= n; i++){
			if(temp % i == 0){
				factor.push_back(i);
				while(temp % i == 0){
					temp /= i;
				}
			}
		}
		
		if(temp > 1){
			factor.push_back(temp);
		}
		
		long long total_cnt = 0;
		
		for(int i = 1; i < (1 << factor.size()); i++){
			long long lcm = 1;
			for(int j = 0; j < factor.size(); j++){
				if(i & (1 << j)){
					lcm = lcm * factor[j] / gcd(lcm, factor[j]);
				}
			}
			
			long long cnt = b / lcm - (a - 1) / lcm;
			
			if(__builtin_popcount(i) % 2 == 1){
				total_cnt += cnt;		
			}else{
				total_cnt -= cnt;
			}
		}
		
		cout << "Case #" << test_case << ": " << b - a + 1 - total_cnt << "\n";
	}
		
	return 0;
}