#include <iostream>
using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n;
	cin >> n;
	
	bool is_prime = true;
	
	if(n == 1){
		is_prime = false;
	}
	
	for(long long i = 2; i * i <= n; i++){
		if(n % i == 0){
			is_prime = false;
			break;
		}
	}
	
	if(is_prime){
		long long temp = n;
		long long reverse = 0;
		while(temp > 0){
			if(temp % 10 == 3 or temp % 10 == 4 or temp % 10 == 7){
				is_prime = false;
				break;
			}else if(temp % 10 == 6){
				reverse = reverse * 10 + 9;
			}else if(temp % 10 == 9){
				reverse = reverse * 10 + 6;
			}else{
				reverse = reverse * 10 + temp % 10;
			}
			temp /= 10;
		}
		
		for(long long i = 2; i * i <= reverse; i++){
			if(reverse % i == 0){
				is_prime = false;
				break;
			}
		}
		
		if(is_prime){
			cout << "yes";
		}else{
			cout << "no";
		}
	}else{
		cout << "no";
	}
	
	return 0;
}