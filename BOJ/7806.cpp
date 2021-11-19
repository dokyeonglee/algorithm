#include <iostream>
using namespace std;

long long pow(long long a, long long n){
	if(n == 0){
		return 1;
	}
	long long temp = pow(a, n / 2);
	temp = temp * temp;
	if(n % 2 == 1){
		temp = temp * a;
	}
	return temp;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n, k;
	
	while(!cin.eof() and cin >> n >> k){
		
		long long answer = 1;
		long long temp = k;
		
		if(n == 0){
			cout << 1 << "\n";
			continue;
		}
		
		for(long long i = 2; i * i <= temp; i++){
			
			if(k < i){
				break;
			}
			
			long long a = 0;
			
			while(k % i == 0){
				k /= i;
				a++;
			}
			
			if(a > 0){
				long long b = 0;
				for(long long j = i; j <= n; j *= i){
					b += n / j;
				}
				answer *= pow(i, min(a, b));
			}
		}
		
		if(k <= n){
			answer *= k;
		}
		
		cout << answer << "\n";
		
	}
	
	return 0;
}