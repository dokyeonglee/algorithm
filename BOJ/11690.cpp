#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	unsigned long long n;
	cin >> n;
	
	vector<bool> is_prime(n + 5, true);
	is_prime[0] = is_prime[1] = false;
	
	for(int i = 2; i * i <= n; i++){
		if(is_prime[i]){
			for(int j = i * i; j <= n; j += i){
				is_prime[j] = false;			
			}
		}
	}
	
	unsigned long long answer = 1;
	
	for(long long i = 2; i <= is_prime.size() and i <= n; i++){
		if(is_prime[i]){
			unsigned long long temp = i;
			while(temp * i <= n){
				temp *= i;
			}
			answer = answer * temp % (1ll << 32);
		}
	}
	
	cout << answer;
	
	return 0;
}